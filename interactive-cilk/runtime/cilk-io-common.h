#ifndef INCLUDED_CILK_IO_COMMON_H 
#define INCLUDED_CILK_IO_COMMON_H 

static inline bool cilk_enqueue_simple_op(const io_future &fut, const int &fildes, void *buf, const size_t &nbyte, const int && type, const int && syscall_no) {
  __cilkrts_worker *self = __cilkrts_get_tls_worker_fast();
  if (self->l->io_queue) {
    io_op_t op = {
      .type = type, // A read syscall
      .syscall_no = syscall_no,
      .fildes = fildes,
      .payload.simple.buf = buf,
      .payload.simple.nbyte = nbyte,
      .res = 0,
      .fut = fut
    };
    io_queue_push(self->l->io_queue, &op);
    return true;
  }

  return false;
}

static inline bool cilk_enqueue_read(const io_future &fut, const int &fildes, void *buf, const size_t &nbyte) {
  return cilk_enqueue_simple_op(fut, fildes, buf, nbyte, IOTYPE__FLAG_READ | IOTYPE__SIMPLE, SYS_read);
}

static inline bool cilk_enqueue_write(const io_future &fut, const int &fildes, void *buf, const size_t &nbyte) {
  return cilk_enqueue_simple_op(fut, fildes, buf, nbyte, IOTYPE__FLAG_WRITE | IOTYPE__SIMPLE, SYS_write);
}

static inline bool cilk_enqueue_accept(const io_future &fut, const int &sockfd, struct sockaddr *addr, socklen_t *addrlen) {
  __cilkrts_worker *self = __cilkrts_get_tls_worker_fast();
  if (self->l->io_queue) {
    io_op_t op = {
      .type = IOTYPE__FLAG_READ | IOTYPE__SOCKET,
      .syscall_no = SYS_accept,
      .fildes = sockfd,
      .payload.socket.addr = addr,
      .payload.socket.addrlen = addrlen,
      .res = 0,
      .fut = fut
    };

    io_queue_push(self->l->io_queue, &op);
    return true;
  }
  return false;
}

#endif
