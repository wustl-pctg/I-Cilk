#ifndef INCLUDED_DEQUE_DOT_H
#define INCLUDED_DEQUE_DOT_H

#include "c_deque.h"

#ifdef __cplusplus

#include <functional>

namespace cilk {

class deque : public c_deque {
  private:
    std::function<void(void)> task;

  public:
    volatile bool validRunnable = false;
    inline std::function<void(void)>* getTaskPtr() { return &task; }
    inline void runTaskAndClear();
    inline void clearTask() { task = std::function<void(void)>(); }
    inline void validateRunnableTaskDeque() {
      CILK_ASSERT(this->task && "Not a valid function object!");
    }

    ~deque() {
      //CILK_ASSERT(d->worker == NULL);
      CILK_ASSERT(this->head == this->tail);

      // if/when we use d->lock or d->steal_lock
      //__cilkrts_mutex_destroy
      __cilkrts_free(this->ltq);
      __cilkrts_free(this->fiber_ltq);
    }
};

}

std::function<void(void)>* __cilkrts_deque_get_task_ptr(void *d);

#endif // ifdef __cplusplus

__CILKRTS_BEGIN_EXTERN_C
bool deque_is_runnable(void *void_d); 
void fiber_proc_to_execute_task(cilk_fiber *fiber); 
c_deque* __cilkrts_allocate_deque();
void deque_destroy(c_deque *cd);
//void deque_free(c_deque *cd);
__CILKRTS_END_EXTERN_C

#endif
