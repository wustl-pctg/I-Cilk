#ifndef __CILK__FUTURE_H__
#define __CILK__FUTURE_H__

#include <assert.h>
#include <functional>
//#include <vector>
//#include <internal/abi.h>
#include <internal/future_base.h>
//#include <pthread.h>
#include <cilk/handcomp-macros.h>
#include <cilk/sync_handle.h>

namespace cilk {

// NOTE: This is the easy method for using futures,
//       but the handcomp version has less overhead.
//       Unfortunately, there is not compiler support
//       for futures yet.
#define cilk_future_create(fut,func,args...)\
  __cilk_future_wrapper<decltype(func), func>(fut,##args);

#define cilk_future_get(fut)              (fut)->get()

#define cilk_spawn2_void(func, args...)\
  __loc_sync_handle.incrementPutCount();\
  __cilk_sync_handle_void_wrapper<decltype(func), func>(&__loc_sync_handle, ##args);

#define cilk_spawn2(dest, func, args...)\
  __loc_sync_handle.incrementPutCount();\
  __cilk_sync_handle_wrapper<decltype(func), func, decltype(dest)>(&dest, &__loc_sync_handle, ##args);
  
#define cilk_spawn3(dest, func, args...)\
    __loc_sync_handle.spawn<decltype(func), func>(&dest, ##args);


// TODO: The sync handle can be stored with priority commands
#define cilk_sync2()\
  __loc_sync_handle.get();

template<typename T>
class future : public future_base {
private:
  volatile T m_result;

public:

  future() {
    tail = &head;
  };

  ~future() {
  }

  void __attribute__((always_inline)) put(T result) {
    // C++ and its lack of default volatile copy constructors is annoying
    *(const_cast<T*>(&m_result)) = result;
    __asm__ volatile ("" ::: "memory");

    resume_deques();
  };

  T __attribute__((always_inline)) get() {
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
public:
  future() {
     tail = &head;
  };

  ~future() {
  }

  void __attribute__((always_inline)) put(void) {
      resume_deques();
  };

  void __attribute__((always_inline)) get() {
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
  CILK_FUNC_PREAMBLE;

  START_FIRST_FUTURE_SPAWN;
    __cilk_future_create_helper<T,Func, func>(fut,args...);
  END_FUTURE_SPAWN;

  CILK_FUNC_EPILOGUE;
}

// void "template specialization" via function overloading (you cannot specialize functions)
template <typename Func, Func func, typename... Args>
void __attribute__((always_inline)) __cilk_future_wrapper(cilk::future<void> *fut, Args... args) {
  CILK_FUNC_PREAMBLE;

  START_FIRST_FUTURE_SPAWN;
    __cilk_future_create_helper<Func, func>(fut,args...);
  END_FUTURE_SPAWN;

  CILK_FUNC_EPILOGUE;
}

#endif // #ifndef __CILK__FUTURE_H__
