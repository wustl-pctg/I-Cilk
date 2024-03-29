#include <cilk/cilk.h>
#include <cilk/cilk_io.h>

#include <string.h>

#include <unistd.h>

#include "fib/fib.h"
#include "fib/common/fib-producer.h"
#include "fib/common/fib-options.h"
#include "common/ktiming.h"

#include <inttypes.h>
#include <malloc.h>

#define m_fib_func  fib

int fib_n = 30;
int fib_count = 3000;
int io_delay = 50000;
int nruns = 1;

void run_bench(int fd, int depth) {
    uint64_t in_buf;

    read(fd, &in_buf, sizeof(uint64_t));
    if (depth >= fib_count) return;
    cilk_spawn run_bench(fd, depth+1);

    m_fib_func(fib_n);
}

int main(int argc, char *args[]) {
    load_fib_options(argc, args);

    uint64_t *running_times = (uint64_t*)malloc(nruns*sizeof(uint64_t));
    clockmark_t begin, end;

    for (int i = 0; i < nruns; i++) {
        begin = ktiming_getmark();

        int recv_fd = create_producer(io_delay);

        cilk_spawn run_bench(recv_fd, 0);
        cilk_sync;

        close(recv_fd);

        end = ktiming_getmark();
        running_times[i] = ktiming_diff_usec(&begin, &end);
    }

    if(nruns > 10) 
        print_runtime_summary(running_times, nruns); 
    else 
        print_runtime(running_times, nruns); 

    free(running_times);

    return 0;
}
