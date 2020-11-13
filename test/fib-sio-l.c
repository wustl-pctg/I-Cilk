#include <cilk/cilk.h>
#include <cilk/cilk_io.h>

#include <string.h>

#include <fcntl.h>
#include <unistd.h>

#include "fib.h"
#include "fib-producer.h"
#include "fib-options.h"
#include "ktiming.h"

#include <inttypes.h>
#include <malloc.h>

#define m_fib_func  fib

int fib_n = 30;
int fib_count = 3000;
int io_delay = 50000;
int nruns = 1;

void run_bench(int fd, int depth) {
    io_future_result io_res = { 0, 0};
    io_future fut;
    uint64_t in_buf;

    if (depth >= fib_count) return;

    fut = cilk_read(fd, &in_buf, sizeof(uint64_t));
    cilk_spawn run_bench(fd, depth+1);
    io_res = cilk_iosync(&fut);
    m_fib_func(fib_n);
}

int main(int argc, char *args[]) {
    load_fib_options(argc, args);

    uint64_t *running_times = (uint64_t*)malloc(nruns*sizeof(uint64_t));
    clockmark_t begin, end;

    for (int i = 0; i < nruns; i++) {
        begin = ktiming_getmark();

        int recv_fd = create_producer(io_delay);

        int saved_flags = fcntl(recv_fd, F_GETFL);
        fcntl(recv_fd, F_SETFL, saved_flags | O_NONBLOCK);

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
