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

#include <stdio.h>

#define m_fib_func  fib

int fib_n = 30;
int fib_count = 5000;
int io_delay = 50000;
int nruns = 5;

int getValue(int unused) {
  uint64_t in_buf;
  int prod_fd = create_oneshot_producer(io_delay);
  int saved_flags = fcntl(prod_fd, F_GETFL);
  fcntl(prod_fd, F_SETFL, saved_flags | O_NONBLOCK);
  io_future f = cilk_read(prod_fd, &in_buf, sizeof(uint64_t));
  cilk_iosync(&f);
  close(prod_fd);
  return fib_n;
}

int run_bench(int start, int end) {
  int n = end - start;
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    int x = getValue(start);
    return m_fib_func(x);
  } else {
    int piv = (start + end) / 2;
    int res1 = 0;
    res1 = cilk_spawn run_bench(start, piv);
    int res2 = run_bench(piv, end);
    cilk_sync;
    return res1 + res2;
  }
}

int main(int argc, char *args[]) {
  load_fib_options(argc, args);

  uint64_t *running_times = (uint64_t*)malloc(nruns*sizeof(uint64_t));
  clockmark_t begin, end;

  for (int i = 0; i < nruns; i++) {
    begin = ktiming_getmark();
    cilk_spawn run_bench(0, fib_count);
    cilk_sync;
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
