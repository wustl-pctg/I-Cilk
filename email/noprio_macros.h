#pragma once

#include <cilk/sync_handle.h>
#include <cilk/future.h>
#include <cilk/cilk_main.h>

namespace cilk {
  typedef int Low;

  template <typename T, typename P>
  class pfuture : public future<T> { };
}

#define cilk_enable_diff_prio_spawn_in_this_func()\
  cilk_enable_spawn_in_this_func()

#define cilk_pfuture_create(args...)\
  cilk_future_create(args)

#define cilk_pfuture_get(args...)\
  cilk_future_get(args)

#define cilk_pspawn(prio, dest, args...)\
  cilk_spawn3((*dest), args)

#define cilk_pspawn_void(prio, args...)\
  cilk_spawn3_void(args)

#define cilk_psync\
  cilk_sync2()

#define CilkPrioCommandPrototype(retT, funcName, argList...)\
  retT funcName(argList);

#define CilkPrioCommandDefine(retT, funcName, argList, body...)\
  retT funcName argList body

#define CilkDeclareNewPriority(prio1, prio2)\
  typedef prio2 prio1;

#define UNUSED(var) ((void*)&var)

#define cilk_reset_desires()

#define cilk_set_rho(new_rho) UNUSED(new_rho)

#define  cilk_get_rho() 0

#define  cilk_set_util_bound(new_util_bound) UNUSED(new_util_bound)

#define  cilk_get_util_bound() 0

#define  cilk_set_quantum_length_us(new_quantum_length_us) UNUSED(new_quantum_length_us)

#define  cilk_get_quantum_length_us() 0 

#define  cilk_set_initial_desire(initial_desire) UNUSED(initial_desire)

#define  cilk_get_initial_desire() 0

#define  cilk_set_round_robin_worker_count(worker_count) UNUSED(worker_count)

#define  cilk_get_round_robin_worker_count() 0

#define  cilk_set_reserved_workers_per_level(reserved) UNUSED(reserved)
#define  cilk_get_reserved_workers_per_level() 0
