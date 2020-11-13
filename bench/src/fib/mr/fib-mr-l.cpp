//#include <cilk/cilk.h>
//#include <cilk/cilk_io.h>
#include <cilk/cilk_priority.h>

#include <string.h>

#include <fcntl.h>
#include <unistd.h>

#include "fib/fib.h"
#include "fib/common/fib-producer.h"
#include "fib/common/fib-options.h"
#include "common/ktiming.h"

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
  //io_future f = cilk_read(prod_fd, &in_buf, sizeof(uint64_t));
  //cilk_iosync(&f);
  cilk_read_sync(prod_fd, &in_buf, sizeof(uint64_t));
  close(prod_fd);
  return fib_n;
}

CilkPrioCommandPrototype(int, run_bench, int, int);
CilkPrioCommandDefine(int, run_bench, (int start, int end), {
  int n = end - start;
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    int x = getValue(start);
    return cilk_run_command(m_fib_func, x);
  } else {
    cilk_enable_spawn_in_this_func();
    int piv = (start + end) / 2;
    int res1 = 0;
    cilk_pspawn(cilk::Low, &res1, run_bench, start, piv);
    int res2 =  cilk_run_command(run_bench, piv, end);
    cilk_psync;
    return res1 + res2;
  }
}
);

int main(int argc, char *args[]) {
  load_fib_options(argc, args);

  uint64_t *running_times = (uint64_t*)malloc(nruns*sizeof(uint64_t));
  clockmark_t begin, end;
  cilk_enable_spawn_in_this_func();
  int result = 0;

  for (int i = 0; i < nruns; i++) {
    begin = ktiming_getmark();
    cilk_pspawn(cilk::Low, &result, run_bench, 0, fib_count);
    cilk_psync;
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
