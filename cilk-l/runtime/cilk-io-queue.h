#ifndef INCLUDED_CILK_IO_QUEUE_H
#define INCLUDED_CILK_IO_QUEUE_H

#include <sys/types.h>
#include <cilk/cilk_io.h>

#include "cilk-io-op.h"

#define DEFAULT_IO_Q_SIZE (4096)
#define IO_Q_SIZE(q)      (DEFAULT_IO_Q_SIZE)

typedef struct io_queue_t {
  volatile size_t head;
  volatile size_t tail;
  int eventfd;
  volatile io_op_t q[DEFAULT_IO_Q_SIZE];
} io_queue_t;

#ifdef __cplusplus
extern "C" {
#endif

io_queue_t* new_io_queue();
void del_io_queue(io_queue_t* q);

void io_queue_push(io_queue_t* q, io_op_t* op);
io_op_t io_queue_pop(io_queue_t* q);

#ifdef __cplusplus
}
#endif

#endif
