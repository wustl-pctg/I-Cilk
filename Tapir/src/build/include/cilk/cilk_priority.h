#ifndef INCLUDED_CILK_PRIORITY_H
#define INCLUDED_CILK_PRIORITY_H

#include <assert.h>
#include <type_traits>
#include <functional>

#include <cilk/sync_handle.h>
#include <cilk/future.h>
#include <cilk/cilk_io.h>

#include <internal/abi.h>
#include <cilk/handcomp-macros.h>

#ifdef DONT_USE_PRIORITY_SCHEDULER
constexpr int levelIncrement = 0;
#else
constexpr int levelIncrement = 1;
#endif

extern void __cilkrts_allocate_runnable_task_deque(void**, std::function<void(void)>**, int);
extern "C" {
void __cilkrts_throw_deque(void*);
void priority_scheduler_yield(); 
}
// Scheduler functions
extern void cilk_reset_desires(); 
extern void cilk_set_rho(const float new_rho); 
extern float cilk_get_rho(); 
extern void cilk_set_util_bound(const float new_util_bound); 
extern float cilk_get_util_bound(); 
extern void cilk_set_quantum_length_us(const int new_quantum_length_us); 
extern int cilk_get_quantum_length_us(); 
extern void cilk_set_initial_desire(float initial_desire); 
extern float cilk_get_initial_desire(); 
extern void cilk_set_round_robin_worker_count(int worker_count); 
extern int cilk_get_round_robin_worker_count(); 
extern void cilk_set_reserved_workers_per_level(int reserved); 
extern int cilk_get_reserved_workers_per_level(); 

extern int __cilk_highestSchedulingLevel; // Initial value is 0

namespace cilk {

template <class, class, typename, typename...> class command;
template <typename, class> class pfuture;

template <class Command>
Command cmd_launch_obj = Command();


/**
 * The lowest priority in the system.
 **/
class Low {
  public:
    /** The scheduling level indicates which level of the
     *  Cilk scheduler will be used for jobs at this priority.
     **/
    static constexpr int schedulingLevel = 0;
    /** A field to hold a unique ID for this priority. */
    //static int priorityID = 0;
};

#define CILK_PRIO_CAT(A, B) A ## B
#define CILK_PRIO_CAT3(A, B, C) A ## B ## C
#define CILK_CMD_NAME(funcName) CILK_PRIO_CAT3(CilkInternal_, funcName, _Command)

#define cilk_run_command(funcName, args...)\
  cilk::__cilk_run_command<CILK_CMD_NAME(funcName)<decltype(this->__internal_cilk_priority_type())> >(args)

#define CilkPrioWrapTemplate(args...) args

#define CilkPrioCommandPrototype(retType, funcName, argList...)\
  template <class __INTERNAL_CILK_P>\
  class CILK_CMD_NAME(funcName) : public cilk::command<CILK_CMD_NAME(funcName)<__INTERNAL_CILK_P>, __INTERNAL_CILK_P, retType, ##argList> {\
      public:\
        retType __run(argList);\
    };

#define CilkPrioCommandDefine(retType, funcName, args, body...)\
  template <class __INTERNAL_CILK_P>\
  retType CILK_CMD_NAME(funcName)<__INTERNAL_CILK_P>::__run args body;

#define cilk_get_curr_priority() decltype(this->__internal_cilk_priority_type())

/** NewPrio is the name of the priority being declared;
  * NextLowestPriority is the priority immediately lower
  * than the current priority. Any two priorities that
  * are defined specifying the same "NextLowestPrio"
  * will be scheduled at the same level, but they cannot
  * sync with each other (their priorities are not comparable).
  *
  * The "constructor" function is set up such that it will run
  * after any lower scheduling level's "constructor" runs,
  * guaranteeing we will get the max value for the 
  * highestSchedulingLevel variable and a unique ID
  * for the priority class. The priority of the
  * constructor (i.e. when it runs relative to others) is
  * NewPrio::schedulingLevel+100 since first 100 constructor
  * priorities are reserved by the system.
  *
  * Downside: there could be lots of constructor calls.
  **/
#define CilkDeclareNewPriority(NewPrio, NextLowestPrio)\
  class NewPrio : public NextLowestPrio {\
    public:\
           static constexpr int schedulingLevel =\
                                  NextLowestPrio::schedulingLevel + levelIncrement;\
           /*static int priorityID = -1;*/\
  };\
  __attribute__((constructor (NewPrio::schedulingLevel+100))) __attribute__((weak)) void CILK_PRIO_CAT(NewPrio, UpdatePrioLevel)() {\
    __cilk_highestSchedulingLevel = NewPrio::schedulingLevel;\
    /*if (NewPrio::priorityID == -1) NewPrio::priorityID = cilk::numberOfPriorities++;*/\
  }

template <class P1, class P2>
/**
 * A helper "function" for determining whether two priorities are the same.
 **/
struct priorityTheSame {
  static_assert(std::is_base_of< cilk::Low, P1>::value && std::is_base_of< cilk::Low, P2>::value,
     "Attempted to use an invalid priority!");
  static constexpr bool value = std::is_same< P2, P1 >::value;
};

template <class P1, class P2>
/**
 * A helper "function" for determining whether a priority is strictly greater than another.
 * Tests P1 to see if its priority is strictly greater than that of P2. If they are not
 * comparable, then this will result in false (we don't have that relationship defined)
 **/
struct priorityGreaterThan {
  static_assert(std::is_base_of< cilk::Low, P1>::value && std::is_base_of< cilk::Low, P2>::value,
     "Attempted to use an invalid priority!");
  static constexpr bool value = std::is_base_of< P2, P1 >::value && !(std::is_same< P1, P2>::value);
};

template <class P1, class P2>
/**
 * A helper "function" for determining whether a priority is lower than another.
 * Tests P1 to see if its priority is not lower than that of P2. If they are not
 * comparable, then this will result in false (we don't have that relationship defined)
 **/
struct priorityNotLowerThan {
  static_assert(std::is_base_of< cilk::Low, P1>::value && std::is_base_of< cilk::Low, P2>::value,
     "Attempted to use an invalid priority!");
  static constexpr bool value = std::is_base_of< P2, P1 >::value;
};

template <class P1, class P2>
/**
 * A helper "function" for determining whether a priority is strictly lower than another.
 * Tests P1 to see if its priority is strictly lower than that of P2. If they are not
 * comparable, then this will result in false (we don't have that relationship defined)
 **/
struct priorityLowerThan {
  static_assert(std::is_base_of< cilk::Low, P1>::value && std::is_base_of< cilk::Low, P2>::value,
     "Attempted to use an invalid priority!");
  static constexpr bool value = std::is_base_of< P1, P2 >::value && !(std::is_same< P1, P2 >::value);
};

#define __pspawn_asserts(sp_cmd) \
  static_assert(cilk::priorityNotLowerThan<decltype(sp_cmd::__internal_cilk_priority_type()), decltype(this->__internal_cilk_priority_type()) >::value,\
      "Cannot pspawn a lower priority from a higher priority");

template <class Command, class P, typename RetType, typename... Args>
void __thrown_future_helper(cilk::pfuture< RetType, P >* fut, Args... args) {
  // If the return type is void, only the first branch gets compiled;
  // else the other branch is compiled
  if constexpr (std::is_same<RetType, void>::value) {
    cmd_launch_obj<Command>.__run(args...);
    __asm__ volatile ("" ::: "memory");
    fut->put();
  } else {
    fut->put(cmd_launch_obj<Command>.__run(args...));
  }
}

/*template <class Command, class P, typename RetType = void, typename... Args>
void __thrown_future_helper(cilk::pfuture< void, P >* fut, Args... args) {
}
*/

template <class Command, class P, typename RetType, typename... Args>
inline void __future_throw_set_function(std::function<void(void)>* task, cilk::pfuture<RetType, P> *fut, Args... args) {
    *task = std::bind(__thrown_future_helper<Command, P, RetType, Args...>, fut, args...);
}

// TODO: The static assert on __cilk__internal__can__spawn
//       doesn't actually help....I would like to make it work somehow
#define cilk_pspawn(prio, var, funcName, args...)\
{\
  static_assert(std::is_base_of<cilk::Low, prio>::value,\
      "Attempted to use an invalid priority!");\
  static_assert(__cilk__internal__can__spawn,\
      "ERROR: Must call cilk_enable_spawn_in_this_func before using pspawn");\
  __pspawn_asserts(CILK_CMD_NAME(funcName)<prio>);\
  constexpr bool __cilk__internal__cilkPrioSpawnSame = cilk::priorityTheSame<prio, decltype(this->__internal_cilk_priority_type())>::value;\
  if constexpr(__cilk__internal__cilkPrioSpawnSame\
      || !levelIncrement) {\
    if (!CILK_SETJMP(__loc_sync_handle.sf.ctx)) {\
      cilk::cmd_launch_obj<CILK_CMD_NAME(funcName)<prio>>.__spawnRun(var, ##args);\
    }\
  } else {\
    static_assert(__cilk__internal__cilkPrioSpawnSame || __cilk__internal__can__spawn__diff_prio, "ERR: Need to call cilk_enable_diff_prio_spawn_in_this_func()");\
    void *task_deque;\
    std::function<void(void)> *task;\
    __cilkrts_allocate_runnable_task_deque(&task_deque, &task, prio::schedulingLevel);\
    __loc_sync_handle.incrementPutCount();\
    cilk::__spawn_throw_set_function< CILK_CMD_NAME(funcName)<prio> >(task, (var), &__loc_sync_handle, ##args);\
    __cilkrts_throw_deque(task_deque);\
  }\
}

#define cilk_pspawn_void(prio, funcName, args...)\
{\
  static_assert(std::is_base_of<cilk::Low, prio>::value,\
      "Attempted to use an invalid priority!");\
  static_assert(__cilk__internal__can__spawn,\
      "ERROR: Must call cilk_enable_spawn_in_this_func before using pspawn");\
  __pspawn_asserts(CILK_CMD_NAME(funcName)<prio>);\
  constexpr bool __cilk__internal__cilkPrioSpawnSame = cilk::priorityTheSame<prio, decltype(this->__internal_cilk_priority_type())>::value;\
  if constexpr(__cilk__internal__cilkPrioSpawnSame\
      || !levelIncrement) {\
    if (!CILK_SETJMP(__loc_sync_handle.sf.ctx)) {\
      cilk::cmd_launch_obj<CILK_CMD_NAME(funcName)<prio> >.__spawnRun(NULL, ##args);\
    }\
  } else {\
    static_assert(__cilk__internal__cilkPrioSpawnSame || __cilk__internal__can__spawn__diff_prio, "ERR: Need to call cilk_enable_diff_prio_spawn_in_this_func()");\
    void *task_deque;\
    std::function<void(void)> *task;\
    __cilkrts_allocate_runnable_task_deque(&task_deque, &task, prio::schedulingLevel);\
    __loc_sync_handle.incrementPutCount();\
    cilk::__spawn_throw_set_function_void< CILK_CMD_NAME(funcName)<prio> >(task, &__loc_sync_handle, ##args);\
    __cilkrts_throw_deque(task_deque);\
  }\
}

#define cilk_psync\
  __loc_sync_handle.get();

#define cilk_pfuture_create(fut, funcName, args...)\
  (fut)->__internal_mark_created();\
  if constexpr(cilk::priorityTheSame<decltype((fut)->__internal_cilk_priority_type()), decltype(this->__internal_cilk_priority_type())>::value\
      || !levelIncrement) {\
    cilk::cmd_launch_obj<CILK_CMD_NAME(funcName)<decltype((fut)->__internal_cilk_priority_type())> >.__futureRun((fut), ##args);\
  } else {\
    void *task_deque;\
    std::function<void(void)> *task;\
    __cilkrts_allocate_runnable_task_deque(&task_deque, &task, decltype((fut)->__internal_cilk_priority_type())::schedulingLevel);\
    cilk::__future_throw_set_function< CILK_CMD_NAME(funcName)<decltype((fut)->__internal_cilk_priority_type())> >(task, (fut), ##args);\
    __cilkrts_throw_deque(task_deque);\
  }

#define cilk_pfuture_get(f) \
  (f)->get();\
  static_assert(cilk::priorityNotLowerThan< decltype((f)->__internal_cilk_priority_type()), decltype(this->__internal_cilk_priority_type()) >::value,\
      "Cannot touch a future that has a lower priority than the current job!");


template <class P>
/** A base class for any object with a priority. 
 *  <p>
 *  A base class for any object with a priority. This allows for a standard
 *  interface for getting the associated priority. For the rest of the system
 *  to work as intended, any prioritized objects should inherit from
 *  {@code prioritized_entity}. The function {@code p} should not be implemented
 *  manually in other classes as such duplication would not be easily
 *  maintainable.
 *  <\p>
 **/
class prioritized_entity {
  public:
    /**
     * Get the priority of the object. Can be interpreted by the compiler.
     *
     * @return An instance of the priority object.
     **/
    static constexpr P __internal_cilk_priority_type() { 
      static_assert(std::is_base_of<cilk::Low, P>::value,\
        "Attempted to use an invalid priority!");\
      return P();
    }
};

template <typename Command, typename T = typename Command::retT, typename... Args> 
inline T __cilk_run_command(Args... args) {
  return cmd_launch_obj<Command>.__run(args...);
}

template <class Command, typename RetType, typename... Args>
void __thrown_spawn_helper(RetType* dest, cilk::sync_handle* handle, Args... args) {
  *dest = cmd_launch_obj<Command>.__run(args...);
  __asm__ volatile ("" ::: "memory");
  handle->put();
}

template <class Command, typename... Args>
void __thrown_spawn_void_helper(cilk::sync_handle* handle, Args... args) {
  cmd_launch_obj<Command>.__run(args...);
  __asm__ volatile ("" ::: "memory");
  handle->put();
}

template <class Command, typename RetType, class SyncHandle, typename... Args>
inline void __spawn_throw_set_function(std::function<void(void)>* task, RetType* dest, SyncHandle* handle, Args... args) {
  if constexpr(std::is_same<SyncHandle, cilk::sync_handle>::value) {
    *task = std::bind(__thrown_spawn_helper<Command, RetType, Args...>, dest, handle, args...); 
  } else {
    assert(0); // lw_sync_handle; should not get here
  }
}

template <class Command, class SyncHandle, typename... Args>
inline void __spawn_throw_set_function_void(std::function<void(void)>* task, SyncHandle* handle, Args... args) {
  if constexpr(std::is_same<SyncHandle, cilk::sync_handle>::value) {
    *task = std::bind(__thrown_spawn_void_helper<Command, Args...>, handle, args...); 
  } else {
    assert(0); // lw_sync_handle; should not get here
  }
}

template <class UserCmd, class __INTERNAL_CILK_P, typename retType, typename... Args>
/**
 * A base class for prioritized commands.
 **/
class command : public prioritized_entity<__INTERNAL_CILK_P> {
  public:
    using retT = retType;

    command() {};

    void __attribute__((noinline)) __futureRunHelper(pfuture<retT, __INTERNAL_CILK_P> *fut, Args... args) {
      FUTURE_HELPER_PREAMBLE;

        if constexpr (std::is_same<void, retT>::value) {
          static_cast<UserCmd*>(this)->__run(args...);
          __sync_synchronize();
          fut->put();
        } else {
          fut->put(static_cast<UserCmd*>(this)->__run(args...));
        }

      FUTURE_HELPER_EPILOGUE;
    }

    inline void __futureRun(pfuture<retT, __INTERNAL_CILK_P> *fut, Args... args) {
      START_FIRST_FUTURE_SPAWN__INTEROP;
        this->__futureRunHelper(fut, args...);
      END_FUTURE_SPAWN__INTEROP;
    }

    /**
     * The function to be used when running the command when spawned.
     **/
    void __attribute__((noinline)) __spawnRun(retT *result, Args... args) {
      SPAWN_HELPER_PREAMBLE;

        if constexpr (std::is_same<void, retT>::value) {
          static_cast<UserCmd*>(this)->__run(args...);
        } else {      
          *result = static_cast<UserCmd*>(this)->__run(args...);
        }

      SPAWN_HELPER_EPILOGUE;
    }

};

template <typename T, class P>
/**
 * A future handle for a future task that has a priority.
 **/
class pfuture : public future<T>, public prioritized_entity<P> {
  public:
    pfuture() {
      this->reset();
    }
};

template <class P>
/**
 * A future handle for a future task that has a priority; void specialization.
 **/
class pfuture<void, P> : public future<void>, public prioritized_entity<P> {
  public:
    pfuture() {
      this->reset();
    }
};

} // namespace cilk

class PriorityMain : public cilk::prioritized_entity<cilk::Low> {
public:
  int main(int argc, char *args[]);
};

extern FILE* utilOutput;
extern bool closeUtilOutput;

extern double avgUtil;
extern double maxUtil;
extern double avgL;
// TODO: We should define main elsewhere
int __attribute__((weak)) main(int argc, char *args[]) {
  CILK_INITIAL_FUNC_PREAMBLE;
  
    ::PriorityMain userProgram;
    int result = userProgram.main(argc, args);
    //return userProgram.main(argc, args);

  CILK_FUNC_EPILOGUE;

  fprintf(utilOutput, "Avg Util: %lg\n", avgUtil);
  fprintf(utilOutput, "Max Util: %lg\n", maxUtil);
  fprintf(utilOutput, "Avg L(us): %lg\n", avgL / 1000.0);
  fflush(utilOutput);

  if (closeUtilOutput) fclose(utilOutput);

  return result;
}
#define main ::PriorityMain::main

#undef cilk_spawn
#undef cilk_sync
#define cilk_spawn static_assert(0, "Cannot mix traditional cilk_spawn and the priority type system!");
#define cilk_sync  static_assert(0, "Cannot mix traditional cilk_sync and the priority type system!");

template <class P>
inline void cilk_pread_internal(cilk::pfuture<io_future_result, P>* fut, int fildes, void *buf, size_t nbyte) {
  cilk_read(static_cast<cilk::future<io_future_result>*>(fut),
      fildes, buf, nbyte);
}

template <class P>
inline void cilk_pwrite_internal(cilk::pfuture<io_future_result, P>* fut, int fildes, void *buf, size_t nbyte) {
  cilk_write(static_cast<cilk::future<io_future_result>*>(fut),
      fildes, buf, nbyte);
}

template <class P>
inline void cilk_paccept_internal(cilk::pfuture<io_future_result, P> *fut, int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
  cilk_accept(static_cast<cilk::future<io_future_result>*>(fut),
      sockfd, addr, addrlen);
}

// void cilk_pread(cilk::pfuture<io_future_result, P> *fut, int sockfd, struct sockaddr *addr, socklen_t *addrlen);
#define cilk_pread(fut, fildes, buf, nbyte)\
  static_assert(cilk::priorityNotLowerThan< decltype((fut)->__internal_cilk_priority_type()), decltype(this->__internal_cilk_priority_type()) >::value,\
      "I/O must be done at a priority greater than or equal to that of the current thread!");\
  cilk_pread_internal((fut), fildes, buf, nbyte);

// void cilk_pwrite(cilk::pfuture<io_future_result, P> *fut, int sockfd, struct sockaddr *addr, socklen_t *addrlen);
#define cilk_pwrite(fut, fildes, buf, nbyte)\
  static_assert(cilk::priorityNotLowerThan< decltype((fut)->__internal_cilk_priority_type()), decltype(this->__internal_cilk_priority_type()) >::value,\
      "I/O must be done at a priority greater than or equal to that of the current thread!");\
  cilk_pwrite_internal((fut), fildes, buf, nbyte);

#define cilk_paccept(fut, sockfd, addr, addrlen)\
  static_assert(cilk::priorityNotLowerThan< decltype((fut)->__internal_cilk_priority_type()), decltype(this->__internal_cilk_priority_type()) >::value,\
      "I/O must be done at a priority greater than or equal to that of the current thread!");\
  cilk_paccept_internal((fut), sockfd, addr, addrlen);

#endif
