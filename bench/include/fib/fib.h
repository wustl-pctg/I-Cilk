#ifndef __INCLUDED__FIB__H__
#define __INCLUDED__FIB__H__


extern int serial_base_case;

// Serial recursive fibonacci calculation
int serial_fib(int n);

#ifndef DONT_USE_PRIORITY

#include <cilk/cilk_priority.h>

// Fork-join recursive fibonacci calculation
//int fib(int n);
CilkPrioCommandPrototype(int, fib, int);
CilkPrioCommandDefine(int, fib, (int n), {
    if (n <= serial_base_case) {
        return serial_fib(n);
    }

    cilk_enable_spawn_in_this_func();

    int x = 0;
    int y = 0;
    
    //x = cilk_spawn fib(n-1);
    cilk_pspawn(cilk_get_curr_priority(), &x, fib, n-1);
    y = cilk_run_command(fib, n-2);
    cilk_psync;
    return x+y;
}
);

#else

// Fork-join recursive fibonacci calculation
//int fib(int n);
int fib(int n);

#endif

#endif
