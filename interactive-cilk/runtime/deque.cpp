#include <internal/abi.h>
#include <functional>
#include "local_state.h"
#include "full_frame.h"
#include "c_deque.h"
#include "deque.h"

void cilk::deque::runTaskAndClear() {
  this->validRunnable = false;
  __asm__ volatile ("" ::: "memory");
  CILK_ASSERT(this->task);
  this->task();
  // Clear out the function object so that it is invalid
  // and any memory that was allocated for arguments is released
  this->task = std::function<void(void)>(); 
}

std::function<void(void)>* __cilkrts_deque_get_task_ptr(void *d) {
  return (static_cast<cilk::deque*>(d))->getTaskPtr();
}

void __cilkrts_allocate_runnable_task_deque(void **d, std::function<void(void)>** func, int scheduling_level) {
  __cilkrts_worker *w = __cilkrts_get_tls_worker_fast();
  cilk::deque *deque_view = new cilk::deque();
  CILK_ASSERT(deque_view);
  deque_view->validRunnable = true;
  *d = static_cast<void*>(deque_view);
  deque_init((c_deque*) deque_view, w->g->ltqsize, scheduling_level);
  *func = __cilkrts_deque_get_task_ptr(*d);
  deque_view->resumable = DEQUE__RUNNABLE_TASK;
  deque_view->saved_ped = w->pedigree;
  cilkg_increment_active_workers(w->g, scheduling_level);
}

__CILKRTS_BEGIN_EXTERN_C
extern void __cilkrts_pop_frame(__cilkrts_stack_frame*);

bool deque_is_runnable(void *void_d) {
  cilk::deque *d = static_cast<cilk::deque*>(void_d);
  return d->validRunnable;
}

// TODO: Look at detach func; need to update pedigree information accordingly on resume
void fiber_proc_to_execute_task(cilk_fiber *fiber) {
  cilk::deque *d = static_cast<cilk::deque*>(__cilkrts_get_deque());
  CILK_ASSERT(d->validRunnable);
  d->validRunnable = false;
  //d->validateRunnableTaskDeque();
  __cilkrts_stack_frame sf;
  __cilkrts_enter_frame_fast_1(&sf);
  sf.flags |= CILK_FRAME_DETACHED;

  __cilkrts_worker *w = __cilkrts_get_tls_worker_fast();
  (*(w->l->frame_ff))->call_stack = &sf;
  d->call_stack = &sf;
  // TODO: finish ensuring the stack frame stuff is correct;
  //       also make sure the pedigree fields are set correctly-ish

  d->validRunnable = false;
  __asm__ volatile ("" ::: "memory");
  (*(d->getTaskPtr()))();
  if (((void*)d) == __cilkrts_get_deque()) {
    d->clearTask();
  }

  //d->runTaskAndClear();

  __cilkrts_pop_frame(&sf);
  __cilkrts_leave_frame(&sf);
  CILK_ASSERT(!"We should never make it back to this point!");
}

c_deque* __cilkrts_allocate_deque() {
  return static_cast<c_deque*>(new cilk::deque());
}


void deque_destroy(c_deque *cd) {
  cilk::deque *d = static_cast<cilk::deque*>(cd);
  delete d;
}

__CILKRTS_END_EXTERN_C
