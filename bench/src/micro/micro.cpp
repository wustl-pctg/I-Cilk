#ifndef DONT_USE_PRIORITY
#include <cilk/cilk_priority.h>
#else
#include <cilk/cilk_main.h>
#endif
#include "cilk/sync_handle.h"
#include <cilk/cilk_api.h>
#include <cilk/cilk_io.h>

#include "common/getoptions.h"
#include "common/ktiming.h"
#include "fib/fib.h"
#include "fib/common/fib-options.h"

#include <sys/types.h>
#include <unistd.h>
#include <sys/timerfd.h>
#include <inttypes.h>
#include <string.h>

#include "micro.h"

int resp_records = 64;

int fib_n = 42;

int nruns = 10;

// all unused, but need to define for fib-options
int fib_count = 1;
int io_delay = 0;

char lp_types[10];
int lp_type = UNUSED;
int lp_procs = 0;
uint64_t lp_work = 0;
uint64_t lp_interval = 0;

char mp_types[10];
int mp_type = UNUSED;
int mp_procs = 0;
uint64_t mp_work = 0;
uint64_t mp_interval = 0;

char hp_types[10];
int hp_type = UNUSED;
int hp_procs = 0;
uint64_t hp_work = 0;
uint64_t hp_interval = 0;

#ifndef DONT_USE_PRIORITY
typedef cilk::Low Low;

#ifndef SINGLE_PRIO
CilkDeclareNewPriority(Medium, Low);
CilkDeclareNewPriority(High, Medium);
#else
typedef Low Medium;
typedef Low High;
#endif
#else // defined(SINGLE_PRIO)
extern void cilk_reset_desires(); 
extern void cilk_set_rho(const float new_rho); 
extern float cilk_get_rho(); 
extern void cilk_set_util_bound(const float new_util_bound); 
extern float cilk_get_util_bound(); 
extern void cilk_set_quantum_length_us(const int new_quantum_length_us); 
extern int cilk_get_quantum_length_us(); 
extern void cilk_set_initial_desire(float initial_desire); 
extern float cilk_get_initial_desire(); 
extern void cilk_set_round_robin_worker_count(int worker_count); 
extern int cilk_get_round_robin_worker_count(); 
extern void cilk_set_reserved_workers_per_level(int reserved); 
extern int cilk_get_reserved_workers_per_level(); 
#endif

volatile int done = 0;

#ifndef DONT_USE_PRIORITY
CilkPrioCommandPrototype(int, timed_fib, int, clockmark_t*, clockmark_t*);
CilkPrioCommandDefine(int, timed_fib, (int n, clockmark_t* begin, clockmark_t* end), {
#else
int timed_fib (int n, clockmark_t* begin, clockmark_t* end) {
#endif
  *begin = ktiming_getmark();  
  __asm__ volatile ("" ::: "memory");
  //__sync_synchronize();
#ifndef DONT_USE_PRIORITY
  int res = cilk_run_command(fib, n);
#else
  int res = fib(n);
#endif
  //__sync_synchronize();
  __asm__ volatile ("" ::: "memory");
  *end = ktiming_getmark();
  return res;
}    
#ifndef DONT_USE_PRIORITY
);
#endif

#ifndef DONT_USE_PRIORITY
CilkPrioCommandPrototype(void, spin, void);
CilkPrioCommandDefine(void, spin, (), {
#else
void spin (void) {
#endif
  cilk_enable_spawn_in_this_func();
  serial_fib(15);
#ifndef DONT_USE_PRIORITY
  cilk_pspawn_void(cilk_get_curr_priority(), spin);
#else
  cilk_spawn3_void(spin);
#endif
}
#ifndef DONT_USE_PRIORITY
);
#endif

int spin_quantum = 50;
#ifndef DONT_USE_PRIORITY
CilkPrioCommandPrototype(void, spinfor, uint64_t);
CilkPrioCommandDefine(void, spinfor, (uint64_t time), {
#else
void spinfor (uint64_t time) {
#endif
  uint64_t end = ktiming_getmark() + (time * 1000);
  //cilk_enable_spawn_in_this_func();

  //Doesn't actually spin, but we shouldn't be able to hide the latency
  //of usleep
  /*if (time < spin_quantum) {
    usleep((useconds_t)time);
  }
  else {
    usleep((useconds_t)spin_quantum);
#ifndef DONT_USE_PRIORITY
    cilk_pspawn_void(cilk_get_curr_priority(), spinfor, time - spin_quantum);
    cilk_psync;
#else
    cilk_spawn3_void(spinfor, time - spin_quantum);
    cilk_sync2();
#endif
  }
  //usleep(1000);
  //serial_fib(15);
  */
  while (ktiming_getmark() < end);

}
#ifndef DONT_USE_PRIORITY
);
#endif

#ifndef DONT_USE_PRIORITY
CilkPrioCommandPrototype(int, kprocs, int);
CilkPrioCommandDefine(int, kprocs, (int P), {
#else
int kprocs (int P) {
#endif
  cilk_enable_spawn_in_this_func();

  for (int i = 0; i < P; i++) {
#ifndef DONT_USE_PRIORITY
    cilk_pspawn_void(cilk_get_curr_priority(), spin);
#else
    cilk_spawn3_void(spin);
#endif
  }
#ifndef DONT_USE_PRIORITY
  cilk_psync;
#else 
  cilk_sync2();
#endif
  return 0;

}
#ifndef DONT_USE_PRIORITY
);
#endif

#ifndef DONT_USE_PRIORITY
CilkPrioCommandPrototype(int, bprocs, int, uint64_t, uint64_t, clockmark_t *, clockmark_t *, clockmark_t *, int);
CilkPrioCommandDefine(int, bprocs, (int P, uint64_t dur, uint64_t intv, clockmark_t* init, clockmark_t* begin, clockmark_t* end, int records), {
#else
int bprocs (int P, uint64_t dur, uint64_t intv, clockmark_t* init, clockmark_t* begin, clockmark_t* end, int records) {
#endif
  cilk_enable_spawn_in_this_func();

  //int N = __cilkrts_get_nworkers() - 2;

  //uint64_t off = on * (N - P) / P;
  int timer_fd = timerfd_create(CLOCK_MONOTONIC, 0);

  uint64_t in_buf;

  //printf("on: %lu, off: %lu\n", on, off);

  struct itimerspec timeout;
  timeout.it_value.tv_sec = intv / 1000000;
  timeout.it_value.tv_nsec = (intv % 1000000) * 1000;

  // Make sure the timer doesn't block forever!
  if (timeout.it_value.tv_sec == 0 && timeout.it_value.tv_nsec == 0) {
    timeout.it_value.tv_nsec = 1;
  }

  timeout.it_interval.tv_sec = 0;
  timeout.it_interval.tv_nsec = 0;

  int it = 0;
  __asm__ volatile ("" ::: "memory");
  //init[0] = ktiming_getmark() - (intv * 1000);
  __asm__ volatile ("" ::: "memory");
  for (it = 0; !done; it++) {
    __asm__ volatile ("" ::: "memory");
    if (it <= records && it > 0) begin[it-1] = ktiming_getmark();
    __asm__ volatile ("" ::: "memory");
    //printf("Spawning\n");
    for (int i = 0; i < P; i++) {
#ifndef DONT_USE_PRIORITY
      cilk_pspawn_void(cilk_get_curr_priority(), spinfor, dur);
#else
      cilk_spawn3_void(spinfor, dur);
#endif
    }
#ifndef DONT_USE_PRIORITY
    cilk_psync;
#else
    cilk_sync2();
#endif
    __asm__ volatile ("" ::: "memory");
    if (it <= records && it > 0)  end[it-1] = ktiming_getmark();
    __asm__ volatile ("" ::: "memory");
    //printf("Synced\n");

    __asm__ volatile ("" ::: "memory");
    //if (it+1 < records) init[it+1] = ktiming_getmark();
    __asm__ volatile ("" ::: "memory");

    timerfd_settime(timer_fd, 0, &timeout, NULL);

#ifndef DONT_USE_PRIORITY
    cilk::pfuture<io_future_result, cilk_get_curr_priority()> timefut;
    cilk_pread(&timefut, timer_fd, &in_buf, sizeof(uint64_t));
#else
    base_io_fut timefut;
    cilk_read(&timefut, timer_fd, &in_buf, sizeof(uint64_t));
#endif


#ifndef DONT_USE_PRIORITY    
    cilk_pfuture_get(&timefut);
#else
    cilk_future_get(&timefut);
#endif
    if (it < records) init[it] = timefut.getPutTime();
  }
  close(timer_fd);
  return (it-1);
  }
#ifndef DONT_USE_PRIORITY
  );
#endif


const char *quant_specifiers[] = {
  "-lt", "-lp", "-ld", "-li", "-mt", "-mp", "-md", "-mi", "-ht", "-hp", "-hd",
  "-hi", "-L", "-rho", "-util", "-init-desire", "-rr-workers",
  "-reserved-workers", "-nruns", "-n", "-b", 0
};

int quant_opt_types[] = {
  STRINGARG, INTARG, INTARG, INTARG, STRINGARG, INTARG, INTARG, INTARG,
  STRINGARG, INTARG, INTARG, INTARG, INTARG, FLOATARG, FLOATARG, FLOATARG,
  INTARG, INTARG, INTARG, INTARG, INTARG, 0
};

void failargs(const char *msg) {
  printf("%s", msg);
  exit(1);
}

#ifndef DONT_USE_PRIORITY
CilkPrioCommandPrototype(void, Start);
CilkPrioCommandDefine(void, Start, (void), {
#else
void Start(void) {
#endif

  cilk_enable_spawn_in_this_func();

  uint64_t running_time[nruns];

  clockmark_t begin, end;
  begin = ktiming_getmark();

  int highResult = 0;
  int medResult = 0;
  int lowResult = 0;
  clockmark_t init[3][resp_records];
  clockmark_t beginning[3][resp_records];
  clockmark_t ending[3][resp_records];
  uint64_t highTime[nruns];
  uint64_t highLaunchTime[nruns];
  int highOffset = 0;
  uint64_t highRespTime[resp_records*nruns];
  uint64_t highWorkTime[resp_records*nruns];
  uint64_t highRespWorkTime[resp_records*nruns];
  uint64_t medTime[nruns];
  uint64_t medLaunchTime[nruns];
  int medOffset = 0;
  uint64_t medRespTime[resp_records*nruns];
  uint64_t medWorkTime[resp_records*nruns];
  uint64_t medRespWorkTime[resp_records*nruns];
  uint64_t lowTime[nruns];
  uint64_t lowLaunchTime[nruns];
  int lowOffset = 0;
  uint64_t lowRespTime[nruns*resp_records];
  uint64_t lowWorkTime[nruns*resp_records];
  uint64_t lowRespWorkTime[resp_records*nruns];

  clockmark_t launchBegin;

  for (int k = 0; k < nruns; k++) {
#ifndef DONT_USE_PRIORITY
    cilk::pfuture<int, Low> lowfut;
    cilk::pfuture<int, Medium> medfut;
    cilk::pfuture<int, High> highfut;
#else
    cilk::future<int> lowfut;
    cilk::future<int> medfut;
    cilk::future<int> highfut;
#endif

    done = 0;

    cilk_reset_desires();

    __asm__ volatile ("" ::: "memory");
    launchBegin = ktiming_getmark();
    __asm__ volatile ("" ::: "memory");

    switch (hp_type) {
    case COMP:
      //beginning[0][k] = (clockmark_t *) malloc(sizeof(clockmark_t));
      //ending[0][k] = (clockmark_t *) malloc(sizeof(clockmark_t));
#ifndef DONT_USE_PRIORITY
      cilk_pfuture_create(&highfut, timed_fib, fib_n, beginning[0], ending[0]);
#else
      cilk_future_create(&highfut, timed_fib, fib_n, beginning[0], ending[0]);
#endif
      break;
      //case CONST:
      //cilk_pfuture_create(&highfut, kprocs, hp_procs);
      //break;
    case BURST:
      //init[0] = (clockmark_t *) malloc(resp_records * sizeof(clockmark_t));
      //beginning[0] = (clockmark_t *) malloc(resp_records * sizeof(clockmark_t));
      //ending[0] = (clockmark_t *) malloc(resp_records * sizeof(clockmark_t));
#ifndef DONT_USE_PRIORITY
      cilk_pfuture_create(&highfut, bprocs, hp_procs, hp_work, hp_interval, init[0], beginning[0], ending[0], resp_records);
#else
      cilk_future_create(&highfut, bprocs, hp_procs, hp_work, hp_interval, init[0], beginning[0], ending[0], resp_records);
#endif
      break;
  
    default:
      break;
    }
    switch (mp_type) {
    case COMP:
#ifndef DONT_USE_PRIORITY
      cilk_pfuture_create(&medfut, timed_fib, fib_n, beginning[1], ending[1]);
#else
      cilk_future_create(&medfut, timed_fib, fib_n, beginning[1], ending[1]);
#endif
      break;
      //case CONST:
      //cilk_pfuture_create(&highfut, kprocs, hp_procs);
      //break;
    case BURST:
#ifndef DONT_USE_PRIORITY
      cilk_pfuture_create(&medfut, bprocs, mp_procs, mp_work, mp_interval, init[1], beginning[1], ending[1], resp_records);
#else
      cilk_future_create(&medfut, bprocs, mp_procs, mp_work, mp_interval, init[1], beginning[1], ending[1], resp_records);
#endif
      break;
    default:
      break;
    }
    switch (lp_type) {
    case COMP:
#ifndef DONT_USE_PRIORITY
      cilk_pfuture_create(&lowfut, timed_fib, fib_n, beginning[2], ending[2]);
#else
      cilk_future_create(&lowfut, timed_fib, fib_n, beginning[2], ending[2]);
#endif
      break;
      //case CONST:
      //cilk_pfuture_create(&highfut, kprocs, hp_procs);
      //break;
    case BURST:
#ifndef DONT_USE_PRIORITY
      cilk_pfuture_create(&lowfut, bprocs, lp_procs, lp_work, lp_interval, init[2], beginning[2], ending[2], resp_records);
#else
      cilk_future_create(&lowfut, bprocs, lp_procs, lp_work, lp_interval, init[2], beginning[2], ending[2], resp_records);
#endif
      break;
  
    default:
      break;
    }
  
#ifndef DONT_USE_PRIORITY
    if (lp_type == COMP) lowResult = cilk_pfuture_get(&lowfut);
    if (mp_type == COMP) medResult = cilk_pfuture_get(&medfut);
    if (hp_type == COMP) highResult = cilk_pfuture_get(&highfut);
#else
    if (lp_type == COMP) lowResult = cilk_future_get(&lowfut);
    if (mp_type == COMP) medResult = cilk_future_get(&medfut);
    if (hp_type == COMP) highResult = cilk_future_get(&highfut);
#endif
  
    done = 1;
  
    if (lp_type == BURST) {
#ifndef DONT_USE_PRIORITY
      lowResult = cilk_pfuture_get(&lowfut);
#else
      lowResult = cilk_future_get(&lowfut);
#endif
      for (int i = 0; i < lowResult && i < resp_records; i++) {
        lowRespTime[i+lowOffset] = ktiming_diff_usec(&init[2][i], &beginning[2][i]);// - 1000*lp_interval;
        lowWorkTime[i+lowOffset] = ktiming_diff_usec(&beginning[2][i], &ending[2][i]);
        medRespWorkTime[i+lowOffset] = ktiming_diff_usec(&init[2][i], &ending[2][i]);// - 1000*lp_interval;
      }
      if (lowResult > resp_records) lowOffset += resp_records;
      else lowOffset += lowResult;
    }
    if (mp_type == BURST) {
#ifndef DONT_USE_PRIORITY
      medResult = cilk_pfuture_get(&medfut);
#else
      medResult = cilk_future_get(&medfut);
#endif
      for (int i = 0; i < medResult && i < resp_records; i++) {
        medRespTime[i+medOffset] = ktiming_diff_usec(&init[1][i], &beginning[1][i]);// - 1000*mp_interval;
        medWorkTime[i+medOffset] = ktiming_diff_usec(&beginning[1][i], &ending[1][i]);
        medRespWorkTime[i+medOffset] = ktiming_diff_usec(&init[1][i], &ending[1][i]);// - 1000*mp_interval;
      }
      if (medResult > resp_records) medOffset += resp_records;
      else medOffset += medResult;
    }
    if (hp_type == BURST) {
#ifndef DONT_USE_PRIORITY
      highResult = cilk_pfuture_get(&highfut);
#else
      highResult = cilk_future_get(&highfut);
#endif
      for (int i = 0; i < highResult && i < resp_records; i++) {
        highRespTime[i+highOffset] = ktiming_diff_usec(&init[0][i], &beginning[0][i]);// - 1000*hp_interval;
        highWorkTime[i+highOffset] = ktiming_diff_usec(&beginning[0][i], &ending[0][i]);
        highRespWorkTime[i+highOffset] = ktiming_diff_usec(&init[0][i], &ending[0][i]);// - 1000*hp_interval;
      }
      if (highResult > resp_records) highOffset += resp_records;
      else highOffset += highResult;
    }
  
    if (hp_type == COMP) {
      highTime[k] = ktiming_diff_usec(beginning[0], ending[0]);
      highLaunchTime[k] = ktiming_diff_usec(&launchBegin, ending[0]);
    }
    if (mp_type == COMP) {
      medTime[k] = ktiming_diff_usec(beginning[1], ending[1]);
      medLaunchTime[k] = ktiming_diff_usec(&launchBegin, ending[1]);
    }
    if (lp_type == COMP) {
      lowTime[k] = ktiming_diff_usec(beginning[2], ending[2]);
      lowLaunchTime[k] = ktiming_diff_usec(&launchBegin, ending[2]);
    }
  
  
    //printf("Result: %d\n", x);
  
    end = ktiming_getmark();
    running_time[k] = ktiming_diff_usec(&begin, &end);
  }

#ifndef SINGLE_PRIO
  printf("----------Overall----------\n");
  print_runtime_summary(running_time, nruns);
  if (hp_type == COMP) {
    printf("----------High (Fib) ----------\n");
    printf("**From Job Start**\n");
    print_runtime_summary(highTime, nruns);
    printf("**From Job Create**\n");
    print_runtime_summary(highLaunchTime, nruns);
  } else if (hp_type == BURST) {
    printf("-------High (Interaction)------\n");
    printf("Num: %d (%d collected)\n", highResult, highOffset);
    if (highOffset > 0) {
      printf("**Response Time**\n");
      print_runtime_summary(highRespTime, highOffset);
      printf("**From Job Start**\n");
      print_runtime_summary(highWorkTime, highOffset);
    }
    else
      printf("No responses completed\n");
  }
  if (mp_type == COMP) {
    printf("---------Medium (Fib)---------\n");
    printf("**From Job Start**\n");
    print_runtime_summary(medTime, nruns);
    printf("**From Job Create**\n");
    print_runtime_summary(medLaunchTime, nruns);
  } else if (mp_type == BURST) {
    printf("-----Medium (Interaction)-----\n");
    printf("Num: %d (%d collected)\n", medResult, medOffset);
    if (medOffset > 0) {
      printf("**Response Time**\n");
      print_runtime_summary(medRespTime, medOffset);
      printf("**From Job Start**\n");
      print_runtime_summary(medWorkTime, medOffset);
    }
    else
      printf("No responses completed\n");
  }
  if (lp_type == COMP) {
    printf("-----------Low (Fib)----------\n");
    printf("**From Job Start**\n");
    print_runtime_summary(lowTime, nruns);
    printf("**From Job Create**\n");
    print_runtime_summary(lowLaunchTime, nruns);
  } else if (lp_type == BURST) {
    printf("------Low (Interaction)-------\n");
    printf("Num: %d (%d collected)\n", lowResult, lowOffset);
    if (lowOffset > 0) {
      printf("**Response Time**\n");
      print_runtime_summary(lowRespTime, lowOffset);
      printf("**From Job Start**\n");
      print_runtime_summary(lowWorkTime, lowOffset);
    }
    else
      printf("No responses completed\n");
  }

  if (hp_type == COMP) {
    print_csv_summary(highLaunchTime, nruns, "micro (high comp),");
  } else if (hp_type == BURST) {
    if (highOffset > 0) {
      print_csv_summary(highRespTime, highOffset, "micro (high resp),");
      print_csv_summary(highWorkTime, highOffset, "micro (high work),");
      print_csv_summary(highRespWorkTime, highOffset, "micro (high overall),");
    }
  }

  if (mp_type == COMP) {
    print_csv_summary(medLaunchTime, nruns, "micro (med comp),");
  } else if (mp_type == BURST) {
    if (medOffset > 0) {
      print_csv_summary(medRespTime, medOffset, "micro (med resp),");
      print_csv_summary(medWorkTime, medOffset, "micro (med work),");
      print_csv_summary(medRespWorkTime, medOffset, "micro (med overall),");
    }
  }

  if (lp_type == COMP) {
    print_csv_summary(lowLaunchTime, nruns, "micro (low comp),");
  } else if (lp_type == BURST) {
    if (lowOffset > 0) {
      print_csv_summary(lowRespTime, lowOffset, "micro (low resp),");
      print_csv_summary(lowWorkTime, lowOffset, "micro (low work),");
      print_csv_summary(lowRespWorkTime, lowOffset, "micro (low overall),");
    }
  }

  uint64_t allTimes[3*nruns];
  int i = 0;
  if (hp_type == COMP) {
    for (int j = 0; j < nruns; j++) {
      allTimes[i] = highLaunchTime[j];
      i++;
    }
  }
  if (mp_type == COMP) {
    for (int j = 0; j < nruns; j++) {
      allTimes[i] = medLaunchTime[j];
      i++;
    }
  }
  if (lp_type == COMP) {
    for (int j = 0; j < nruns; j++) {
      allTimes[i] = lowLaunchTime[j];
      i++;
    }
  }
  print_csv_summary(allTimes, i, "micro (all comp),");
  printf("----------Per Task----------\n");
  //print_runtime(allTimes, i);
  print_runtime_summary(allTimes, i-1);

#else

  printf("----------Overall----------\n");
  print_runtime_summary(running_time, nruns);
  uint64_t allTimes[3*nruns];
  int i = 0;
  if (hp_type == COMP) {
    for (int j = 0; j < nruns; j++) {
      allTimes[i] = highTime[j];
      i++;
    }
  }
  if (mp_type == COMP) {
    for (int j = 0; j < nruns; j++) {
      allTimes[i] = medTime[j];
      i++;
    }
  }
  if (lp_type == COMP) {
    for (int j = 0; j < nruns; j++) {
      allTimes[i] = lowTime[j];
      i++;
    }
  }
  printf("----------Per Task----------\n");
  //print_runtime(allTimes, i);
  print_runtime_summary(allTimes, i);

#endif
}
#ifndef DONT_USE_PRIORITY
);
#endif

void init_type_string(char *s) {
  s[0] = 'u';
  s[1] = 'n';
  s[2] = 'u';
  s[3] = 's';
  s[4] = 'e';
  s[5] = 'd';
  s[6] = 0;
}

int main(int argc, char *argv[]) {
  int cilk_quantum_length_us = cilk_get_quantum_length_us();
  float cilk_rho = cilk_get_rho();
  float cilk_util_bound = cilk_get_util_bound();
  float cilk_init_desire = cilk_get_initial_desire();
  int cilk_rr_worker_count = cilk_get_round_robin_worker_count();
  int cilk_reserved_w_per_lvl = cilk_get_reserved_workers_per_level();

  init_type_string(lp_types);
  init_type_string(mp_types);
  init_type_string(hp_types);

  get_options(
              argc, argv, quant_specifiers, quant_opt_types, &lp_types,
              &lp_procs, &lp_work, &lp_interval, &mp_types, &mp_procs, &mp_work,
              &mp_interval, &hp_types, &hp_procs, &hp_work, &hp_interval,
              &cilk_quantum_length_us, &cilk_rho, &cilk_util_bound,
              &cilk_init_desire, &cilk_rr_worker_count,
              &cilk_reserved_w_per_lvl, &nruns, &fib_n, &serial_base_case
  );

  cilk_set_quantum_length_us(cilk_quantum_length_us);
  cilk_set_rho(cilk_rho);
  cilk_set_util_bound(cilk_util_bound);
  cilk_set_initial_desire(cilk_init_desire);
  cilk_set_round_robin_worker_count(cilk_rr_worker_count);
  cilk_set_reserved_workers_per_level(cilk_reserved_w_per_lvl);

  if (!(strcmp(lp_types, "comp"))) {
    lp_type = COMP;
    if (lp_procs != 0) failargs("procs argument is meaningless with COMP");
    if (lp_work != 0) failargs("work argument is meaningless with COMP");
    if (lp_interval != 0) failargs("interval argument is meaningless with COMP");
  } else if (!(strcmp(lp_types, "burst"))) {
    lp_type = BURST;
    if (lp_procs == 0) failargs("procs argument is required with BURST");
  } else if (!(strcmp(lp_types, "unused"))) {
    lp_type = UNUSED;
  } else {
    failargs ("invalid workload type for low");
  }
  if (!(strcmp(mp_types, "comp"))) {
    mp_type = COMP;
    if (mp_procs != 0) failargs("procs argument is meaningless with COMP");
    if (mp_work != 0) failargs("work argument is meaningless with COMP");
    if (mp_interval != 0) failargs("interval argument is meaningless with COMP");
  } else if (!(strcmp(mp_types, "burst"))) {
    mp_type = BURST;
    if (mp_procs == 0) failargs("procs argument is required with BURST");
  } else if (!(strcmp(mp_types, "unused"))) {
    mp_type = UNUSED;
  } else {
    failargs ("invalid workload type for medium");
  }
  if (!(strcmp(hp_types, "comp"))) {
    hp_type = COMP;
    if (hp_procs != 0) failargs("procs argument is meaningless with COMP");
    if (hp_work != 0) failargs("work argument is meaningless with COMP");
    if (hp_interval != 0) failargs("interval argument is meaningless with COMP");
  } else if (!(strcmp(hp_types, "burst"))) {
    hp_type = BURST;
    if (hp_procs == 0) failargs("procs argument is required with BURST");
  } else if (!(strcmp(hp_types, "unused"))) {
    hp_type = UNUSED;
  } else {
    failargs ("invalid workload type for high");
  }
  if ((lp_type != COMP) && (mp_type != COMP) && (hp_type != COMP))
    failargs ("at least one priority must have computation");

#ifndef DONT_USE_PRIORITY
  cilk_run_command(Start);
#else
  Start();
#endif

  return 0;
}
