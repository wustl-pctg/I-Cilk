#include <string.h>

#include <unistd.h>

#include "fib/fib.h"
#include "fib/common/fib-options.h"
#include "common/ktiming.h"

#include <inttypes.h>
#include <malloc.h>

#define m_fib_func  serial_fib

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
int __attribute__((noinline)) run_bench(void) {
    return m_fib_func(fib_n);
}

int main(int argc, char *args[]) {
    load_fib_options(argc, args);
    int res = 0;

    uint64_t *running_times = (uint64_t*)malloc(nruns*sizeof(uint64_t));
    clockmark_t begin, end;

    for (int i = 0; i < nruns; i++) {
        begin = ktiming_getmark();

        res = run_bench();

        end = ktiming_getmark();
        running_times[i] = ktiming_diff_usec(&begin, &end);
    }

    printf("Res: %d\n", res);

    if(nruns > 10) 
        print_runtime_summary(running_times, nruns); 
    else 
        print_runtime(running_times, nruns); 

    free(running_times);

    return 0;
}
