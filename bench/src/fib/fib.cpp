#include "fib/fib.h"
#include "cilk/sync_handle.h"

#ifdef DONT_USE_PRIORITY
#define priority_scheduler_yield()
#endif

int serial_base_case = 15;

int serial_fib(int n) {
    if (n < 2) {
      return n;
    }

    priority_scheduler_yield();

    int x = serial_fib(n-1);
    int y = serial_fib(n-2);

    return x+y;
}

int fib(int n) {
  if (n <= serial_base_case) {
    return serial_fib(n);
  }

  cilk_enable_spawn_in_this_func();

  int x = 0;
  int y = 0;


  cilk_spawn3(x, fib, n-1);
  y = fib(n-2);
  cilk_sync2();

  return x+y;
}
