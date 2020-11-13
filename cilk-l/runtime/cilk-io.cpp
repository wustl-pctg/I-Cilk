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

static inline void cilk_read_internal(const io_future &fut, int fildes, void *buf, size_t nbyte) {
  if (!cilk_enqueue_read(fut, fildes, buf, nbyte)) {
    int epoll_fd = epoll_create(1);
    struct epoll_event event;
    memset((void*)&event, 0, sizeof(event));
    event.data.fd = fildes;
    event.events = EPOLLIN;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fildes, &event);
    epoll_wait(epoll_fd, &event, 1, -1);
    close(epoll_fd);

    io_future_result res;
    res.ret_val = syscall(SYS_read, fildes, buf, nbyte);
    res.errno_val = errno;
    ((base_io_fut*)fut.f)->put(std::move(res));
  }
}

static inline void cilk_write_internal(const io_future &fut, int fildes, void *buf, size_t nbyte) {
  if (!cilk_enqueue_write(fut, fildes, buf, nbyte)) {
    int epoll_fd = epoll_create(1);
    struct epoll_event event;
    memset((void*)&event, 0, sizeof(event));
    event.data.fd = fildes;
    event.events = EPOLLOUT;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fildes, &event);
    epoll_wait(epoll_fd, &event, 1, -1);
    close(epoll_fd);

    io_future_result res;
    res.ret_val = syscall(SYS_write, fildes, buf, nbyte);
    res.errno_val = errno;
    ((base_io_fut*)fut.f)->put(std::move(res));
  }
}

static inline void cilk_accept_internal(const io_future &fut, int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
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
    res.ret_val = syscall(SYS_accept, sockfd, addr, addrlen);
    res.errno_val = errno;
    ((base_io_fut*)fut.f)->put(std::move(res));
  }
}

extern "C" {

io_future cilk_read(int fildes, void *buf, size_t nbyte) {
  io_future fut;
  fut.f = (void*) new base_io_fut();

  cilk_read_internal(fut, fildes, buf, nbyte);

  return fut;
}

io_future cilk_write(int fildes, void *buf, size_t nbyte) {
  io_future fut;
  fut.f = (void*) new base_io_fut();

  cilk_write_internal(fut, fildes, buf, nbyte);

  return fut;
}

io_future cilk_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
  io_future fut;
  fut.f = (void*) new base_io_fut();

  cilk_accept_internal(fut, sockfd, addr, addrlen);

  return fut;
}

io_future_result cilk_iosync(io_future *fut) {
  io_future_result ret = ((base_io_fut*)fut->f)->get();

  delete (base_io_fut*)(fut->f);
  fut->f = NULL;

  return ret;
}

} // end extern "C"

void cilk_read(base_io_fut *fut, int fildes, void *buf, size_t nbyte) {
  io_future cfut = { .f = fut };
  cilk_read_internal(cfut, fildes, buf, nbyte);
}

void cilk_write(base_io_fut *fut, int fildes, void *buf, size_t nbyte) {
  io_future cfut = { .f = fut };
  cilk_write_internal(cfut, fildes, buf, nbyte);
}

void cilk_accept(base_io_fut *fut, int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
  io_future cfut = { .f = fut };
  cilk_accept_internal(cfut, sockfd, addr, addrlen);
}
