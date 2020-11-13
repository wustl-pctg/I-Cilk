#ifndef __CILK__FUTURE_H__
#define __CILK__FUTURE_H__

#include <assert.h>
#include <functional>
#include <internal/future_base.h>
#include <cilk/handcomp-macros.h>
#include <inttypes.h>

extern void __cilkrts_allocate_runnable_task_deque(void**, std::function<void(void)>**);
extern "C" {
void __cilkrts_throw_deque(void*);
int64_t cilk_prio_get_current_time_tsc_ticks();
}

namespace cilk {

// NOTE: This is the easy method for using futures,
//       but the handcomp version has less overhead.
//       Unfortunately, there is not compiler support
//       for futures yet.
#define cilk_future_create(fut,func,args...)\
  (fut)->__internal_mark_created();\
  __cilk_future_wrapper<decltype(func), func>(fut,##args);

#define cilk_future_get(fut)              (fut)->get()

#define cilk_procrastinatory_future_create(fut,func,args...)\
  {\
  (fut)->__internal_mark_created();\
  void *task_deque;\
  std::function<void(void)> *task;\
  __cilkrts_allocate_runnable_task_deque(&task_deque, &task);\
  *task = std::bind(__cilk_procrastinatory_future_helper<decltype(func), func, int, int>, (fut), ##args);\
  __cilkrts_throw_deque(task_deque);\
  }


template<typename T>
class future : public future_base {
private:
  volatile T m_result;
  int64_t putTime = 0;

public:

  future() {
    reset();
  };

  ~future() {
  }

  int64_t getPutTime() {
    return putTime;
  }

  void __attribute__((always_inline)) put(T result) {
    assert(created);
    putTime = cilk_prio_get_current_time_tsc_ticks();
    // C++ and its lack of default volatile copy constructors is annoying
    *(const_cast<T*>(&m_result)) = result;
    __asm__ volatile ("" ::: "memory");

    resume_deques();
  };

  T __attribute__((always_inline)) get() {
    assert(created);
    if (!this->ready()) {
      suspend_deque();
    }

    assert(ready());
    // C++ and its lack of default volatile copy constructors is annoying
    return *(const_cast<T*>(&m_result));
  }
}; // class future

// future<void> specialization
template<>
class future<void> : public future_base {
private:
  int64_t putTime = 0;

public:
  future() {
     reset();
  };

  ~future() {
  }

  void __attribute__((always_inline)) put(void) {
      assert(created);
      putTime = cilk_prio_get_current_time_tsc_ticks();
      resume_deques();
  };

  int64_t getPutTime() {
    return putTime;
  }

  void __attribute__((always_inline)) get() {
    assert(created);
    if (!this->ready()) {
      suspend_deque();
    }

    assert(ready());
  }
}; // class future<void>


} // namespace cilk

template <typename T, typename Func, Func func, typename... Args>
void __attribute__((noinline)) __cilk_future_create_helper(cilk::future<T> *fut, Args... args) {
  FUTURE_HELPER_PREAMBLE;
    fut->put(func(args...));
  FUTURE_HELPER_EPILOGUE;
}

template <typename Func, Func func, typename... Args>
void __attribute__((noinline)) __cilk_future_create_helper(cilk::future<void> *fut, Args... args) {
  FUTURE_HELPER_PREAMBLE;
    func(args...);
    __asm__ volatile ("" ::: "memory");\
    fut->put();
  FUTURE_HELPER_EPILOGUE;
}

template <typename Func, Func func, typename T, typename... Args>
void __attribute__((always_inline)) __cilk_future_wrapper(cilk::future<T> *fut, Args... args) {
  START_FIRST_FUTURE_SPAWN__INTEROP;
    __cilk_future_create_helper<T,Func, func>(fut,args...);
  END_FUTURE_SPAWN__INTEROP;
}

// void "template specialization" via function overloading (you cannot specialize functions)
template <typename Func, Func func, typename... Args>
void __attribute__((always_inline)) __cilk_future_wrapper(cilk::future<void> *fut, Args... args) {
  START_FIRST_FUTURE_SPAWN__INTEROP;
    __cilk_future_create_helper<Func, func>(fut,args...);
  END_FUTURE_SPAWN__INTEROP;
}

template <typename Func, Func func, typename T, typename... Args>
void __cilk_procrastinatory_future_helper(cilk::future<T> *fut, Args... args) {
    fut->put(func(args...));
}

template <typename Func, Func func, typename... Args>
void __cilk_procrastinatory_future_helper(cilk::future<void> *fut, Args... args) {
    func(args...);
    __sync_synchronize();
    fut->put();
}

#endif // #ifndef __CILK__FUTURE_H__
