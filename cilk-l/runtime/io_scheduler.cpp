#include "io_scheduler.h"

#include <cilk/future.h>
#include <cilk/cilk_io.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <sys/syscall.h>
#include <unistd.h>

#include <unordered_map>
#include <unordered_set>
#include <deque>

#include "bug.h"
#include "global_state.h"
#include "local_state.h"
#include "os.h"

extern "C" {

void make_worker_io(__cilkrts_worker *w) {
    CILK_ASSERT(WORKER_FREE == w->l->type);
    w->l->type = WORKER_IO;
    w->l->io_queue = new_io_queue();
}

static int perform_io_until_block(io_op_t &op) {
    if (__cilk_io_op_is_simple(&op)) {
      int res;
      do {
        res = syscall(op.syscall_no, op.fildes, op.payload.simple.buf, op.payload.simple.nbyte);
        op.payload.simple.nbyte -= res;
        op.res += res;
        op.payload.simple.buf = (void*)((char*)op.payload.simple.buf + res);
      } while (op.payload.simple.nbyte > 0 && res > 0 && !__cilk_io_op_is_read(&op));

      if (res < 0) {
        op.payload.simple.nbyte += res;
        op.payload.simple.buf = (void*)((char*)op.payload.simple.buf - res);
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
          op.res -= res;
          return 1;
        } else {
          op.res = -1;
        }
      }
    } else {
      CILK_ASSERT(__cilk_io_op_is_socket(&op));
      op.res = syscall(op.syscall_no, op.fildes, op.payload.socket.addr, op.payload.socket.addrlen);
      if (op.res < 0) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
          op.res = 0;
          return 1;
        } else {
          op.res = -1;
        }
      }
    }

    io_future_result fut_val = {
      .ret_val = op.res,
      .errno_val = errno
    };

    ((base_io_fut*)op.fut.f)->put(std::move(fut_val));

    return 0;
}

static void __attribute__((always_inline)) handle_event(const int &fd, std::deque<io_op_t> &op_queue, std::unordered_set<int> &blocked_set, std::unordered_set<int> &unblocked_set) {
  int res = 0;
  while (!op_queue.empty() && res != 1) {
    io_op_t& op = op_queue.front();
    res = perform_io_until_block(op);
    if (res == 0) {
        op_queue.pop_front();
    }
  }
  if (op_queue.empty()) {
    blocked_set.erase(fd);
    unblocked_set.emplace(fd);
  }
}

void handle_close(int fd, std::deque<io_op_t> &blocked_ops_queue, std::unordered_set<int> &blocked_fds) {
  for (auto &each : blocked_ops_queue) {
    ((base_io_fut*)each.fut.f)->put( {.ret_val = -1, .errno_val = EBADF } );
  }
  blocked_ops_queue.clear();
  blocked_fds.erase(fd);
}

void* scheduler_thread_proc_for_io_worker(void* arg) {
  __cilkrts_worker *self = (__cilkrts_worker*)arg;
  __cilkrts_set_tls_worker(self);

  __cilkrts_worker *coworker = self->g->workers[self->self - self->g->P];

  io_op_t curr_op;

  int epoll_fd = epoll_create(4096); // Argument just needs to be positive

  struct epoll_event event;
  memset(&event, 0, sizeof(event));
  event.data.fd = self->l->io_queue->eventfd;
  event.events = EPOLLIN | EPOLLET;

  int num_triggered = 0;
  struct epoll_event triggered_events[4096];
  epoll_ctl(epoll_fd, EPOLL_CTL_ADD, self->l->io_queue->eventfd, &event);
  ssize_t ret_val;

  // The first deque contains read ops, the second deque contains write ops
  std::unordered_map<int, std::pair<std::deque<io_op_t>, std::deque<io_op_t> > > blocked_ops;

  std::unordered_set<int> blocked_read_fds;
  std::unordered_set<int> ready_read_fds;
  std::unordered_set<int> blocked_write_fds;
  std::unordered_set<int> ready_write_fds;
  bool check_queue = true;

  while (!self->g->work_done) {

      num_triggered = epoll_wait(epoll_fd, triggered_events, 4096, -1);

      if (num_triggered == -1 && errno == EINTR) continue;

      if (num_triggered < 0) {
          __cilkrts_bug("epoll_wait returned an error (%s)\n", strerror(errno));
      }
      for (int i = 0; i < num_triggered; i++) {
          int fd = triggered_events[i].data.fd;
          if (fd == self->l->io_queue->eventfd) {
            check_queue = true;
            continue;
          }
          if (triggered_events[i].events & EPOLLIN) {
              handle_event(fd, blocked_ops[fd].first, blocked_read_fds, ready_read_fds);
          }

					// The file closed
          if ((triggered_events[i].events & EPOLLRDHUP) || (triggered_events[i].events & EPOLLHUP)) {
            if (blocked_ops[fd].first.size()) {
              handle_close(fd, blocked_ops[fd].first, blocked_read_fds);
            }
            if (blocked_ops[fd].second.size()) {
              handle_close(fd, blocked_ops[fd].second, blocked_write_fds);
            }
            blocked_ops.erase(fd);
            epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, NULL); // stop watching me!
            continue;
          }

          if (triggered_events[i].events & EPOLLOUT) {
              handle_event(fd, blocked_ops[fd].second, blocked_write_fds, ready_write_fds);
          }
      }

    if (check_queue) {
        check_queue = false;

        do {
            curr_op = io_queue_pop(self->l->io_queue);

            if (__cilk_io_op_is_read(&curr_op)) {
                if (blocked_read_fds.count(curr_op.fildes)) {
                    blocked_ops[curr_op.fildes].first.emplace_back(std::move(curr_op));
                } else {
                    ret_val = perform_io_until_block(curr_op);
                    // If we would have blocked
                    if (ret_val) {
                         // NOTE: We could have the same file descriptor as a now closed file!
                         //       We will go ahead and add ourselves to epoll again
                         //       (if we are already tracked, we don't get inserted twice)
                         ready_read_fds.erase(curr_op.fildes);
                         blocked_read_fds.emplace(curr_op.fildes);
                         blocked_ops[curr_op.fildes].first.emplace_back(std::move(curr_op));
                         event = {
                             .data.fd = curr_op.fildes,
                             .events = EPOLLRDHUP | EPOLLIN | EPOLLET
                         };

                         if (blocked_write_fds.count(curr_op.fildes)) {
                           event.events |= EPOLLOUT;
                           epoll_ctl(epoll_fd, EPOLL_CTL_MOD, curr_op.fildes, &event);
                         } else {
                           epoll_ctl(epoll_fd, EPOLL_CTL_ADD, curr_op.fildes, &event);
                         }
                    }
                }
            } else if (__cilk_io_op_is_write(&curr_op)) {
                if (blocked_write_fds.count(curr_op.fildes)) {
                    blocked_ops[curr_op.fildes].second.emplace_back(std::move(curr_op));
                } else {
                    CILK_ASSERT(__cilk_io_op_is_simple(&curr_op)); // temp assert; no socket funcs yet
                    ret_val = perform_io_until_block(curr_op);
                    // If we would have blocked
                    if (ret_val) {
                         // NOTE: We could have the same file descriptor as a now closed file!
                         //       We will go ahead and add ourselves to epoll again
                         //       (if we are already tracked, we don't get inserted twice)
                         ready_write_fds.erase(curr_op.fildes);
                         blocked_write_fds.emplace(curr_op.fildes);
                         blocked_ops[curr_op.fildes].second.emplace_back(std::move(curr_op));
                         event = {
                             .data.fd = curr_op.fildes,
                             .events = EPOLLRDHUP | EPOLLOUT | EPOLLET
                         };
                         if (blocked_read_fds.count(curr_op.fildes)) {
                           event.events |= EPOLLIN;
                           epoll_ctl(epoll_fd, EPOLL_CTL_MOD, curr_op.fildes, &event);
                         } else {
                           epoll_ctl(epoll_fd, EPOLL_CTL_ADD, curr_op.fildes, &event);
                         }
                    }
                }
            }
        } while (curr_op.type != IOTYPE__INVALID);
    }

    for (int fd : ready_read_fds) {
		  if (blocked_write_fds.count(fd)) {
				event = { .data.fd = fd, .events = EPOLLRDHUP | EPOLLOUT | EPOLLET };
      	epoll_ctl(epoll_fd, EPOLL_CTL_MOD, fd, &event);
			} else {
      	epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, NULL);
			}
    }
    ready_read_fds.clear();

    for (int fd : ready_write_fds) {
			if (blocked_write_fds.count(fd)) {
        event = { .data.fd = fd, .events = EPOLLRDHUP | EPOLLIN | EPOLLET };
      	epoll_ctl(epoll_fd, EPOLL_CTL_MOD, fd, &event);
			} else {
      	epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, NULL);
			}
    }
    ready_write_fds.clear();

  } // while(!self->g->work_done)

  return NULL;
}

}
