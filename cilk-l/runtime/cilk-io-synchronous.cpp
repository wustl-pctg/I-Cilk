#include <cilk/cilk_io.h>
#include <cilk/future.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include <sys/epoll.h>
#include <string.h>

#include "cilk-io-queue.h"
#include "local_state.h"

#include "cilk-io-common.h"

extern "C" {

ssize_t cilk_read_sync(int fildes, void *buf, size_t nbyte) {
  // Create the future on the stack;
  // we will touch it before returning
  io_future fut;
  base_io_fut stack_fut;
  fut.f = (void *) &stack_fut;

  if (!cilk_enqueue_read(fut, fildes, buf, nbyte)) {
    int epoll_fd = epoll_create(1);
    struct epoll_event event;
    memset((void*)&event, 0, sizeof(event));
    event.data.fd = fildes;
    event.events = EPOLLIN;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fildes, &event);
    epoll_wait(epoll_fd, &event, 1, -1);
    close(epoll_fd);

    // The future doesn't buy us anything since we can't send
    // the I/O to an I/O thread
    return syscall(SYS_read, fildes, buf, nbyte);
  }

  // Synchronize with the future before returning
  io_future_result res = stack_fut.get();
  errno = res.errno_val;
  return res.ret_val;
}

ssize_t cilk_write_sync(int fildes, void *buf, size_t nbyte) {
  // Create the future on the stack;
  // we will touch it before returning
  io_future fut;
  base_io_fut stack_fut;
  fut.f = (void *) &stack_fut;

  if (!cilk_enqueue_write(fut, fildes, buf, nbyte)) {
    int epoll_fd = epoll_create(1);
    struct epoll_event event;
    memset((void*)&event, 0, sizeof(event));
    event.data.fd = fildes;
    event.events = EPOLLOUT;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fildes, &event);
    epoll_wait(epoll_fd, &event, 1, -1);
    close(epoll_fd);

    // The future doesn't buy us anything since we can't send
    // the I/O to an I/O thread
    return syscall(SYS_write, fildes, buf, nbyte);
  }

  // Synchronize with the future before returning
  io_future_result res = stack_fut.get();
  errno = res.errno_val;
  return res.ret_val;
}

int cilk_accept_sync(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
  // Create the future on the stack;
  // we will touch it before returning
  io_future fut;
  base_io_fut stack_fut;
  fut.f = (void *) &stack_fut;
  
  if (!cilk_enqueue_accept(fut, sockfd, addr, addrlen)) {
    int epoll_fd = epoll_create(1);
    struct epoll_event event;
    memset((void*)&event, 0, sizeof(event));
    event.data.fd = sockfd;
    event.events = EPOLLIN;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sockfd, &event);
    epoll_wait(epoll_fd, &event, 1, -1);
    close(epoll_fd);

    io_future_result res;
    return syscall(SYS_accept, sockfd, addr, addrlen);
  }

  // Synchronize with the future before returning
  io_future_result res = stack_fut.get();
  errno = res.errno_val;
  return res.ret_val;
}

}
