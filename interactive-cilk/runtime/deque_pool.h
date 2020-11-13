#ifndef INCLUDED_DEQUE_POOL_DOT_H
#define INCLUDED_DEQUE_POOL_DOT_H

#include <stdlib.h>

#include "c_deque.h"
#include "cilk_fiber.h"

// This is just a simple vector
typedef struct deque_pool_s {
	c_deque ** array;
	volatile size_t size;
	size_t capacity;
  int scheduling_level;
} deque_pool;

void deque_pool_init(deque_pool *p, size_t ltqsize, int scheduling_level);
void deque_pool_free(deque_pool *p);
void deque_pool_add(__cilkrts_worker *victim, deque_pool *p, c_deque *d);
void deque_pool_remove(deque_pool *p, c_deque *d);
void deque_pool_validate(deque_pool *p, __cilkrts_worker *w);

#endif
