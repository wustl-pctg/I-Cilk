//#include <cilk/cilk.h>
//#include <cilk/cilk_io.h>
//#include <cilk/cilk_priority.h>
#ifndef DONT_USE_PRIORITY
#include <cilk/cilk_priority.h>
#else
#include <cilk/cilk_main.h>
#endif

#include <string.h>

#include <unistd.h>

#include "fib/fib.h"
#include "fib/common/fib-options.h"
#include "common/ktiming.h"

#include <inttypes.h>
#include <malloc.h>

#define m_fib_func  fib

int fib_n = 30;
int fib_count = 3000;
int io_delay = 50000;
int nruns = 1;

/* 
 * fib 39: 63245986
 * fib 40: 102334155
 * fib 41: 165580141 
 * fib 42: 267914296
 * fib 43: 433494437
 * fib 44: 701408733
 * fib 45: 1134903170
 */

#ifndef DONT_USE_PRIORITY

CilkPrioCommandPrototype(int, run_bench, void);

CilkPrioCommandDefine(int, run_bench, (void), {
  return cilk_run_command(m_fib_func, fib_n);
}
);

#else

int __attribute__((noinline)) run_bench(void) {
    return m_fib_func(fib_n);
}

#endif

int main(int argc, char *args[]) {
    load_fib_options(argc, args);
    int res = 0;

    uint64_t *running_times = (uint64_t*)malloc(nruns*sizeof(uint64_t));
    clockmark_t begin, end;
    cilk_enable_spawn_in_this_func();

    for (int i = 0; i < nruns; i++) {
        begin = ktiming_getmark();

        //res = cilk_run_command(m_fib_func, fib_n);
#ifndef DONT_USE_PRIORITY
        //cilk_pspawn(cilk_get_curr_priority(), &res, run_bench);
        //cilk_psync;
        res = cilk_run_command(m_fib_func, fib_n);
#else
        cilk_spawn3(res, run_bench);
        cilk_sync2();
#endif

        end = ktiming_getmark();
        running_times[i] = ktiming_diff_usec(&begin, &end);
    }

    printf("Res: %d\n", res);

    if(nruns > 10) 
        print_runtime_summary(running_times, nruns); 
    else 
        print_runtime(running_times, nruns); 

    print_csv_summary(running_times, nruns, "fib-bench,");

    fflush(stdout);
    free(running_times);

    return 0;
}
