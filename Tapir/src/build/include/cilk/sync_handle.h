#ifndef INCLUDED_CILK_SYNC_HANDLE_H
#define INCLUDED_CILK_SYNC_HANDLE_H

#include <cilk/handcomp-macros.h>

extern "C" {
__cilkrts_deque_link* __cilkrts_get_deque_link();
}

namespace cilk {

#define cilk_spawn2_void(func, args...)\
  __loc_sync_handle.incrementPutCount();\
  __cilk_sync_handle_void_wrapper<decltype(func), func>(&__loc_sync_handle, ##args);

#define cilk_spawn2(dest, func, args...)\
  __loc_sync_handle.incrementPutCount();\
  __cilk_sync_handle_wrapper<decltype(func), func, decltype(dest)>(&dest, &__loc_sync_handle, ##args);

#define cilk_spawn3(dest, func, args...)\
    __loc_sync_handle.spawn<decltype(func), func>(&dest, ##args);

#define cilk_spawn3_void(func, args...)\
    __loc_sync_handle.spawnVoid<decltype(func), func>( args );
  
// TODO: The sync handle can be stored with priority commands
#define cilk_sync2()\
  __loc_sync_handle.get();

#define cilk_enable_spawn_in_this_func()\
  constexpr bool __cilk__internal__can__spawn = true;\
  constexpr bool __cilk__internal__can__spawn__diff_prio = false;\
  /* Suppress variable unused warnings */\
  (void)__cilk__internal__can__spawn;\
  (void)__cilk__internal__can__spawn__diff_prio;\
  cilk::lw_sync_handle __loc_sync_handle;

#define cilk_enable_diff_prio_spawn_in_this_func()\
  constexpr bool __cilk__internal__can__spawn = true;\
  constexpr bool __cilk__internal__can__spawn__diff_prio = true;\
  /* Suppress variable unused warnings */\
  (void)__cilk__internal__can__spawn;\
  (void)__cilk__internal__can__spawn__diff_prio;\
  cilk::sync_handle __loc_sync_handle;

class lw_sync_handle final {
public:
  __cilkrts_stack_frame sf;

  lw_sync_handle() {
    __cilkrts_enter_frame_fast_1(&sf);
  }

  ~lw_sync_handle() {
    get();
    __cilkrts_pop_frame(&sf);
    __cilkrts_leave_frame(&sf);
  }

  void __attribute__((always_inline)) get() {
    SYNC;
  }

  void incrementPutCount() {
    assert(0); // NEVER ACTUALLY CALL THIS!
  }

  template <typename Func, Func func, typename T, typename... Args>
  void __attribute__((always_inline)) spawn(T* dest, Args... args) {
    if (!CILK_SETJMP(sf.ctx)) {
      spawnHelper<Func, func>(dest, args...);
    }
  }

  template <typename Func, Func func, typename... Args>
  void __attribute__((always_inline)) spawnVoid(Args... args) {
    if (!CILK_SETJMP(sf.ctx)) {
      spawnHelperVoid<Func, func>(args...);
    }
  }
  
  template <typename Func, Func func, typename T, typename... Args>
  void __attribute__((noinline)) spawnHelper(T* dest, Args... args) {
    SPAWN_HELPER_PREAMBLE;
      *dest = func(args...);
    SPAWN_HELPER_EPILOGUE;
  }

  template <typename Func, Func func, typename... Args>
  void __attribute__((noinline)) spawnHelperVoid(Args... args) {
    SPAWN_HELPER_PREAMBLE;
      func(args...);
    SPAWN_HELPER_EPILOGUE;
  }

};

class sync_handle final {
private:
  volatile uintptr_t put_count;
  volatile uintptr_t deque;

public:
  __cilkrts_stack_frame sf;

  sync_handle() {
    put_count = 0;
    deque = -1;
    __cilkrts_enter_frame_fast_1(&sf);
  }

  ~sync_handle() {
    this->get();
    __cilkrts_pop_frame(&sf);
    __cilkrts_leave_frame(&sf);
  }

  void __attribute__((always_inline)) incrementPutCount() {
    __atomic_fetch_add(&put_count, 1, __ATOMIC_SEQ_CST);
  }

  void __attribute__((always_inline)) put(void) {
    uintptr_t ptr = __atomic_fetch_add(&put_count, -1, __ATOMIC_SEQ_CST);
    if (ptr == deque+1) {
        put_count = 0;
        // The deque should be at a lower priority, else
        // this construct would not have been used
        __cilkrts_make_resumable((void*)deque);
        //__cilkrts_resume_suspended((void*)deque, 2);
    }
  }

  void __attribute__((always_inline)) get() {
    // First sync with jobs at the same priority
    SYNC;
    if (put_count != 0) {
      assert(deque == -1); // "single touch"
      //__atomic_fetch_add(&deque, (uintptr_t)__cilkrts_get_deque_link()->d+1, __ATOMIC_SEQ_CST);
      deque = (uintptr_t)__cilkrts_get_deque_link()->d;
      if (__atomic_fetch_add(&put_count, deque, __ATOMIC_SEQ_CST) != 0) {
        __cilkrts_suspend_deque(0,0);
      } else {
        put_count = 0;
      }
      deque = -1;
    }

  }

  template <typename Func, Func func, typename T, typename... Args>
  void __attribute__((always_inline)) spawn(T* dest, Args... args) {
    if (!CILK_SETJMP(sf.ctx)) {
      spawnHelper<Func, func>(dest, args...);
    }
  }

  template <typename Func, Func func, typename... Args>
  void __attribute__((always_inline)) spawnVoid(Args... args) {
    if (!CILK_SETJMP(sf.ctx)) {
      spawnHelperVoid<Func, func>(args...);
    }
  }
  
  template <typename Func, Func func, typename T, typename... Args>
  void __attribute__((noinline)) spawnHelper(T* dest, Args... args) {
    SPAWN_HELPER_PREAMBLE;
      *dest = func(args...);
    SPAWN_HELPER_EPILOGUE;
  }

  template <typename Func, Func func, typename... Args>
  void __attribute__((noinline)) spawnHelperVoid(Args... args) {
    SPAWN_HELPER_PREAMBLE;
      func(args...);
    SPAWN_HELPER_EPILOGUE;
  }

};

} // namespace cilk

template <typename Func, Func func, typename T, typename... Args>
void __attribute__((noinline)) __cilk_sync_handle_helper(T* dest, cilk::sync_handle *handle, Args... args) {
  FUTURE_HELPER_PREAMBLE;
    *dest = func(args...);
    __sync_synchronize();
    handle->put();
  FUTURE_HELPER_EPILOGUE;
}

template <typename Func, Func func, typename... Args>
void __attribute__((noinline)) __cilk_sync_handle_void_helper(cilk::sync_handle *handle, Args... args) {
  FUTURE_HELPER_PREAMBLE;
    func(args...);
    __sync_synchronize();
    handle->put();
  FUTURE_HELPER_EPILOGUE;
}

template <typename Func, Func func, typename T, typename... Args>
inline void __cilk_sync_handle_wrapper(T* dest, cilk::sync_handle *handle, Args... args) {
  START_FIRST_FUTURE_SPAWN__INTEROP;
    __cilk_sync_handle_helper<Func, func, T>(dest, handle, args...);
  END_FUTURE_SPAWN__INTEROP;
}

template <typename Func, Func func, typename... Args>
void __attribute__((noinline)) __cilk_sync_handle_void_wrapper(cilk::sync_handle *handle, Args... args) {
  START_FIRST_FUTURE_SPAWN__INTEROP;
    __cilk_sync_handle_void_helper<Func, func>(handle,args...);
  END_FUTURE_SPAWN__INTEROP;
}

#endif
