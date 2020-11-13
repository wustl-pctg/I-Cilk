#include "cilk-io-queue.h"
#include "cilk_malloc.h"
#include "os.h"
#include "bug.h"

#include <sys/eventfd.h>
#include <sys/syscall.h>

static const io_op_t inv_op = {
  .type = IOTYPE__INVALID
};

io_queue_t* new_io_queue() {
  io_queue_t* q = __cilkrts_malloc(sizeof(io_queue_t));

  q->head = 0;
  q->tail = 0;

  q->eventfd = eventfd(0, EFD_SEMAPHORE);
  CILK_ASSERT(q->eventfd != -1);

  return q;
}

void del_io_queue(io_queue_t* q) {
  close(q->eventfd);
  __cilkrts_free(q);
}

void io_queue_push(io_queue_t* q, io_op_t* op) {
  size_t t = (q->tail + 1) % IO_Q_SIZE(q);

  while (t == q->head);

  // Write the op to the queue,
  // then update the tail
  q->q[q->tail] = *op;
  __cilkrts_fence();
  q->tail = t;
  __cilkrts_fence();

  // Wake up the IO worker (if sleeping)
  uint64_t val = 1;
  syscall(SYS_write, q->eventfd, &val, 8);
}

io_op_t io_queue_pop(io_queue_t* q) {
  // Empty queue
  if (q->head == q->tail) {
    return inv_op;
  }

  io_op_t ret = q->q[q->head];
  q->head = (q->head + 1) % IO_Q_SIZE(q);

  // Decrement the eventfd counter
  // This is necessary so edge triggered epoll works
  uint64_t val = 0;
  syscall(SYS_read, q->eventfd, &val, 8);

  return ret;
}
