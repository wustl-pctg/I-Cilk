#ifndef INCLUDED_CILK_IO_OP_H
#define INCLUDED_CILK_IO_OP_H

#include <stdbool.h>
#include <sys/socket.h>

#define IOTYPE__INVALID        (0)
#define IOTYPE__SIMPLE         (1)
#define IOTYPE__SOCKET         (2)
#define IOTYPE__FLAG_READ      (1<<31)
#define IOTYPE__FLAG_WRITE     (1<<30)

typedef struct simple_io_t {
  void *buf;
  size_t nbyte;
} simple_io_t;

typedef struct socket_io_t {
  struct sockaddr *addr;
  socklen_t *addrlen;
} socket_io_t;

typedef union io_payload_t {
  simple_io_t simple;
  socket_io_t socket;
} io_payload_t;

typedef struct io_op_t {
  int type;
  int syscall_no;
  int fildes;
  io_future fut;
  ssize_t res;
  io_payload_t payload;
} io_op_t;

static bool __attribute__((always_inline)) __cilk_io_op_is_read(io_op_t *op) {
  return (op->type & IOTYPE__FLAG_READ);
}

static bool __attribute__((always_inline)) __cilk_io_op_is_write(io_op_t *op) {
  return (op->type & IOTYPE__FLAG_WRITE);
}

static bool __attribute__((always_inline)) __cilk_io_op_is_simple(io_op_t *op) {
  // Mask out the flags and compare to the simple type
  return ((op->type & ~(IOTYPE__FLAG_READ | IOTYPE__FLAG_WRITE)) == IOTYPE__SIMPLE);
}

static bool __attribute__((always_inline)) __cilk_io_op_is_socket(io_op_t *op) {
  // Mask out the flags and compare to the simple type
  return ((op->type & ~(IOTYPE__FLAG_READ | IOTYPE__FLAG_WRITE)) == IOTYPE__SOCKET);
}

#endif
