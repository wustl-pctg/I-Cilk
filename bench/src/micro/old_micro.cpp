#include <cilk/cilk_priority.h>

#include "common/getoptions.h"
#include "common/ktiming.h"
#include "fib/fib.h"
#include "fib/common/fib-options.h"

int fib_n = 42;
int nruns = 10;

// all unused, but need to define for fib-options
int fib_count = 1;
int io_delay = 0;


extern int __cilk_quantum_length_us;
extern float __cilk_rho;

typedef cilk::Low Low;

#ifndef SINGLE_PRIO
CilkDeclareNewPriority(Medium, Low);
CilkDeclareNewPriority(High, Medium);
#else
typedef cilk::Low Medium;
typedef cilk::Low High;
#endif


CilkPrioCommandPrototype(int, timed_fib, int, clockmark_t*, clockmark_t*);
CilkPrioCommandDefine(int, timed_fib, (int n, clockmark_t* begin, clockmark_t* end) {
  *begin = ktiming_getmark();  
  __asm__ volatile ("" ::: "memory");
  //__sync_synchronize();
  int res = cilk_run_command(fib, n);
  //__sync_synchronize();
  __asm__ volatile ("" ::: "memory");
  *end = ktiming_getmark();
  return res;
}    
);


const char *quant_specifiers[] = {"-L", "-rho", 0};
int quant_opt_types[] = {INTARG, FLOATARG, 0};
extern void cilk_reset_desires();

int main(int argc, char *argv[]) {
  load_fib_options(argc, argv);
  int __cilk_quantum_length_us = cilk_get_quantum_length_us();
  float __cilk_rho = cilk_get_rho();
  get_options(argc, argv, quant_specifiers, quant_opt_types, &__cilk_quantum_length_us, &__cilk_rho);
  cilk_set_quantum_length_us(__cilk_quantum_length_us);
  cilk_set_rho(__cilk_rho);
  cilk_enable_diff_prio_spawn_in_this_func();

  uint64_t running_time;

  clockmark_t begin, end;
  begin = ktiming_getmark();

  int highResult = 0;
  int medResult = 0;
  int lowResult = 0;
  clockmark_t beginning[3];
  clockmark_t ending[3];
  uint64_t highTime[nruns];
  uint64_t highLaunchTime[nruns];
  uint64_t medTime[nruns];
  uint64_t medLaunchTime[nruns];
  uint64_t lowTime[nruns];
  uint64_t lowLaunchTime[nruns];
  
  clockmark_t launchBegin;


  for (int i = 0; i < nruns; i++) {
    cilk_reset_desires();
    __asm__ volatile ("" ::: "memory");
    launchBegin = ktiming_getmark();
    __asm__ volatile ("" ::: "memory");
    cilk_pspawn(High, &highResult, timed_fib, fib_n, beginning, ending);
    cilk_pspawn(Medium, &medResult, timed_fib, fib_n, beginning+1, ending+1);
    cilk_pspawn(Low, &lowResult, timed_fib, fib_n, beginning+2, ending+2);
    cilk_psync;

    highTime[i] = ktiming_diff_usec(beginning, ending);
    highLaunchTime[i] = ktiming_diff_usec(&launchBegin, ending);
    medTime[i] = ktiming_diff_usec(beginning+1, ending+1);
    medLaunchTime[i] = ktiming_diff_usec(&launchBegin, ending+1);
    lowTime[i] = ktiming_diff_usec(beginning+2, ending+2);
    lowLaunchTime[i] = ktiming_diff_usec(&launchBegin, ending+2);
  }

  //printf("Result: %d\n", x);

  end = ktiming_getmark();
  running_time = ktiming_diff_usec(&begin, &end);

#ifndef SINGLE_PRIO
  printf("----------Overall----------\n");
  print_runtime(&running_time, 1);
  printf("----------High----------\n");
  printf("**From Job Start**\n");
  print_runtime(highTime, nruns);
  printf("**From Job Create**\n");
  print_runtime(highLaunchTime, nruns);
  printf("----------Medium----------\n");
  printf("**From Job Start**\n");
  print_runtime(medTime, nruns);
  printf("**From Job Create**\n");
  print_runtime(medLaunchTime, nruns);
  printf("----------Low----------\n");
  printf("**From Job Start**\n");
  print_runtime(lowTime, nruns);
  printf("**From Job Create**\n");
  print_runtime(lowLaunchTime, nruns);
  printf("\n\n");
  print_csv_summary(highLaunchTime, nruns, "micro (high),");
  print_csv_summary(medLaunchTime, nruns, "micro (med),");
  print_csv_summary(lowLaunchTime, nruns, "micro (low),");
#else
  printf("----------Overall----------\n");
  print_runtime(&running_time, 1);
  uint64_t allTimes[nruns*3];
  for (int i = 0; i < nruns; i++) {
    allTimes[i] = highTime[i];
    allTimes[i+nruns] = medTime[i];
    allTimes[i+2*nruns] = lowTime[i];
  }
  printf("----------Per Task----------\n");
  print_runtime(allTimes, nruns*3);
  print_csv_summary(allTimes, nruns*3, "micro (all)");
#endif
  
  return 0;
}
