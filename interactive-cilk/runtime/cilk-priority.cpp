#include "priority.h"

#include <algorithm>
#include <thread>
#include <chrono>
#include <cstring>

#include <cilk/cilk_priority.h>
#include <internal/abi.h>
#include "global_state.h"
#include "local_state.h"
#include "scheduler.h"

using std::chrono::steady_clock;

FILE* utilOutput = stdout;
bool closeUtilOutput = false;

// This is set to the appropriate values elsewhere
int          __cilk_highestSchedulingLevel = 0;

static volatile int __cilk_quantum_length_us = 1000;
static volatile float __cilk_util_bound = 0.9f;
static volatile float __cilk_rho = 2;
static volatile float __cilk_initial_desire = 1;
static volatile int __cilk_round_robin_worker_count = 0;
static volatile int __cilk_reserved_workers_per_level = 0;

static volatile bool cilk_reset_prio_scheduler = true;

double avgUtil = 0.0;
double maxUtil = 0.0;
double avgL = 0.0;

void cilk_reset_desires() {
  cilk_reset_prio_scheduler = true;
  __sync_synchronize();
  while (__cilk_highestSchedulingLevel && cilk_reset_prio_scheduler);
}

void cilk_set_rho(const float new_rho) {
  __cilk_rho = new_rho;
  __sync_synchronize();
  cilk_reset_prio_scheduler = true;
}

float cilk_get_rho() {
  return __cilk_rho;
}

void cilk_set_util_bound(const float new_util_bound) {
  __cilk_util_bound = new_util_bound;
  __sync_synchronize();
  cilk_reset_prio_scheduler = true;
}

float cilk_get_util_bound() {
  return __cilk_util_bound;
}

void cilk_set_quantum_length_us(const int new_quantum_length_us) {
  __cilk_quantum_length_us = new_quantum_length_us;
  __sync_synchronize();
  cilk_reset_prio_scheduler = true;
}

int cilk_get_quantum_length_us() {
  return __cilk_quantum_length_us;
}

void cilk_set_initial_desire(float initial_desire) {
  __cilk_initial_desire = initial_desire;
  __sync_synchronize();
  cilk_reset_prio_scheduler = true;
}

float cilk_get_initial_desire() {
  return __cilk_initial_desire;
}

void cilk_set_round_robin_worker_count(int worker_count) {
  __cilk_round_robin_worker_count = worker_count;
  __sync_synchronize();
  cilk_reset_prio_scheduler = true;
}

int cilk_get_round_robin_worker_count() {
  return __cilk_round_robin_worker_count;
}

void cilk_set_reserved_workers_per_level(int reserved) {
  __cilk_reserved_workers_per_level = reserved;
  __sync_synchronize();
  cilk_reset_prio_scheduler = true;
}

int cilk_get_reserved_workers_per_level() {
  return __cilk_reserved_workers_per_level;
}

static void __cilkrts_calculate_utilization(float* utilization, float* maxUtilization, int64_t &quantum_end_time, double& time_diff, global_state_t* gstate) {
  //gstate->reading_idle_stats = true;
  __atomic_store_n(&gstate->reading_idle_stats, true, __ATOMIC_RELAXED);
  //__sync_synchronize();
  for (int i = 0; i < gstate->P; ++i) {
    __atomic_exchange_n(&gstate->workers[i]->l->idle_stats_turn, 1, __ATOMIC_ACQ_REL);
    //gstate->workers[i]->l->idle_stats_turn = 1;
  }
  //__sync_synchronize(); 
  for (int i = 0; i < gstate->P; ++i) {
    __cilkrts_worker *curr_w = gstate->workers[i];
    // Wait for all lock
    while(__atomic_load_n(&curr_w->l->idle_stats_turn, __ATOMIC_RELAXED) == 1
        && __atomic_load_n(&curr_w->l->writing_idle_stats, __ATOMIC_ACQUIRE));
  }
  //__asm__ volatile ("" ::: "memory");
  //__sync_synchronize();
  quantum_end_time = cilk_prio_get_current_time_tsc_ticks();
  time_diff = quantum_end_time - gstate->scheduling_level_quantum;
  for (int i = 0; i < gstate->P; ++i) {
    __cilkrts_worker *curr_w = gstate->workers[i];

    int orig_which = curr_w->l->prev_idle_stats;
    int curr_which = curr_w->l->curr_idle_stats;
    int curr_level = curr_w->l->idle_stats[curr_which].scheduling_level;

    if (orig_which != curr_which) {
      int orig_level = curr_w->l->idle_stats[orig_which].scheduling_level;

      int64_t orig_total = curr_w->l->idle_stats[orig_which].idle_time
                     + curr_w->l->idle_stats[orig_which].active_time;

      curr_w->l->prev_idle_stats = curr_w->l->curr_idle_stats;
      maxUtilization[orig_level] += orig_total / time_diff;
      utilization[orig_level] += curr_w->l->idle_stats[orig_which].active_time / time_diff;
      //curr_w->l->idle_stats[orig_which].idle_time = 0;
      //curr_w->l->idle_stats[orig_which].active_time = 0;
    }

    int64_t extra_time = quantum_end_time - curr_w->l->idle_stats[curr_which].state_entered_time;
    int64_t active_time = curr_w->l->idle_stats[curr_which].active_time;
    int64_t idle_time = curr_w->l->idle_stats[curr_which].idle_time;
    if (curr_w->l->idle_stats[curr_which].state == IDLE_STATS__IDLE_STATE) {
      idle_time += extra_time;
    } else {
      active_time += extra_time;
    }

    int64_t curr_total = active_time + idle_time;
    maxUtilization[curr_level] += curr_total / time_diff;
    utilization[curr_level] += active_time / time_diff;
    curr_w->l->idle_stats[curr_which].idle_time = 0;
    curr_w->l->idle_stats[curr_which].active_time = 0;
    curr_w->l->idle_stats[curr_which].state_entered_time = quantum_end_time;
  }

  //__sync_synchronize();
}

extern "C" {

void priority_scheduler_yield() {
  __cilkrts_worker *w = __cilkrts_get_tls_worker_fast();
  if (__builtin_expect(w->l->scheduling_level != w->l->next_scheduling_level, 0)) {
    __cilkrts_suspend_deque(1, 1);
  }
}

void* worker_allocation_scheduler(void* args) {
  // If we have more than one priority...
  if (__builtin_expect(__cilk_highestSchedulingLevel > 0, 1)) {
    global_state_t *gstate = (global_state_t*)args;
    int remaining = 0;
    float *desire = new float[__cilk_highestSchedulingLevel+1]();
    int *allocation = new int[__cilk_highestSchedulingLevel+1]();
    int *actual_allocation = new int[__cilk_highestSchedulingLevel+1]();
    float *utilization = new float[__cilk_highestSchedulingLevel+1]();
    float *maxUtilization = new float[__cilk_highestSchedulingLevel+1]();
    int *nextRoundRobinLevel = new int[gstate->P]();
    bool *firstTimeAtRRLevel = new bool[gstate->P]();
    int active = 0;
    int64_t quantum_end_time = cilk_prio_get_current_time_tsc_ticks();
    double time_since_last_quantum = 0.0;

    cilk_reset_prio_scheduler = true;

    printf("Highest prio level: %d\n", __cilk_highestSchedulingLevel);
    fflush(stdout);

    auto curr_rho = __cilk_rho;
    auto curr_util_bound = __cilk_util_bound;
    auto curr_initial_desire = __cilk_initial_desire;
    auto curr_round_robin_workers = __cilk_round_robin_worker_count;
    auto curr_reserved_workers = __cilk_reserved_workers_per_level;
    auto curr_reserved_or_rr_workers = curr_round_robin_workers + curr_reserved_workers*gstate->P; 
    auto curr_cilk_quantum_length_us = __cilk_quantum_length_us;

    maxUtil = 0.0;
    double currUtil = 0.0;
    avgUtil = 0.0;
    avgL = 0.0;
    uint64_t avgOver = 0;
    //auto sleepTime = curr_cilk_quantum_length_us;

    while (!gstate->work_done) {
      std::fill_n(utilization, __cilk_highestSchedulingLevel+1u, 0.0f);
      std::fill_n(maxUtilization, __cilk_highestSchedulingLevel+1u, 0.0f);

      __cilkrts_calculate_utilization(utilization, maxUtilization, quantum_end_time, time_since_last_quantum, gstate);

      if (__builtin_expect(cilk_reset_prio_scheduler, 0)) {
        // Reload parameters
        curr_initial_desire = __cilk_initial_desire;
        curr_round_robin_workers = __cilk_round_robin_worker_count;
        curr_reserved_workers = __cilk_reserved_workers_per_level * (__cilk_highestSchedulingLevel+1);
        curr_reserved_or_rr_workers = curr_reserved_workers + curr_round_robin_workers;
        curr_rho = __cilk_rho;
        curr_util_bound = __cilk_util_bound;
        curr_cilk_quantum_length_us = __cilk_quantum_length_us;
        //sleepTime = curr_cilk_quantum_length_us;

        for (int i = 0; i < gstate->P; i++) {
          nextRoundRobinLevel[i] = i % (__cilk_highestSchedulingLevel+1);
        }

        std::fill_n(firstTimeAtRRLevel, gstate->P, true);

        // Set all to 0
        std::fill_n(allocation, __cilk_highestSchedulingLevel+1u, 0);
        std::fill_n(actual_allocation, __cilk_highestSchedulingLevel+1u, 0);
        std::fill_n(desire, __cilk_highestSchedulingLevel+1u, 0.0f);

        if (curr_reserved_or_rr_workers < gstate->P) {
          allocation[0] = 1;
          actual_allocation[0] = 1;
          remaining = gstate->P - 1 - curr_reserved_or_rr_workers;
          desire[0] = curr_initial_desire;

          int fairishAllocation = remaining / (__cilk_highestSchedulingLevel+1);
          for (int i = 0; i <= __cilk_highestSchedulingLevel; ++i) {
            actual_allocation[i] += fairishAllocation;
          }
          remaining -= fairishAllocation * (__cilk_highestSchedulingLevel + 1);
          int i = __cilk_highestSchedulingLevel;
          while (remaining--) {
            ++actual_allocation[i--];
          }
        }

        cilk_reset_prio_scheduler = false;

      } else {


        // We have to allocate P processors now
        remaining = gstate->P - curr_reserved_or_rr_workers;

        currUtil = 0.0;

        // Calculate desire and allocation for each priority level
        for (int i = __cilk_highestSchedulingLevel; i >= 0; --i) {
          currUtil += utilization[i];
          // The max utilizaton can be higher than the allocation
          // for the prior quantum since workers are not guaranteed
          // to switch scheduling levels at the appropriate time.
          maxUtilization[i] = (maxUtilization[i] > allocation[i] ? allocation[i] : maxUtilization[i]);
          active = gstate->active_deques_at_prio[i];
          if (active) {
            if (utilization[i] < curr_util_bound * maxUtilization[i]) {
              desire[i] = desire[i] / curr_rho;
            } else if (allocation[i] >= ((int)desire[i])) {
              desire[i] *= curr_rho;
            }
            if (desire[i] < curr_initial_desire) desire[i] = curr_initial_desire;
          } else {
            desire[i] = 0.0f;
          }

          if (desire[i] >= 1.0f && remaining > 0) {
            allocation[i] = (((int)desire[i]) < remaining ? ((int)desire[i]) : remaining);
            remaining -= allocation[i];
          } else {
            allocation[i] = 0;
          }

          actual_allocation[i] = allocation[i];
        }

        if (remaining > 0) {
          int fairishAllocation = remaining / (__cilk_highestSchedulingLevel+1);
          for (int i = 0; i <= __cilk_highestSchedulingLevel; ++i) {
            actual_allocation[i] += fairishAllocation;
          }
          remaining -= fairishAllocation * (__cilk_highestSchedulingLevel + 1);
          int i = __cilk_highestSchedulingLevel;
          while (remaining--) {
            ++actual_allocation[i--];
          }
        }

        maxUtil = (maxUtil > currUtil ? maxUtil : currUtil);
        avgUtil = ((avgUtil * avgOver) + currUtil) / (avgOver+1.0);
        avgL = ((avgL * avgOver) + (time_since_last_quantum)) / (avgOver+1.0);
        //sleepTime = sleepTime - (avgL/1000.0 - curr_cilk_quantum_length_us);
        //sleepTime = (sleepTime <= 0 ? curr_cilk_quantum_length_us : sleepTime);
        ++avgOver;
      }

      int highestFreeLevel = __cilk_highestSchedulingLevel;
      __cilkrts_worker *curr_w;
      for (int i = 0; i < gstate->P - curr_reserved_or_rr_workers; ++i) {
        curr_w = gstate->workers[i];
        // If it is in the user code and we want workers at that level,
        // then keep on chugging along!
        if (cilk_fiber_is_resumable(curr_w->l->scheduling_fiber)
            && actual_allocation[curr_w->l->scheduling_level]
            && curr_w->l->scheduling_level == curr_w->l->next_scheduling_level) {

            --actual_allocation[curr_w->l->scheduling_level];

        // Else if we already told it to switch levels, keep that setting
        } else if (actual_allocation[curr_w->l->next_scheduling_level]) {

            --actual_allocation[curr_w->l->next_scheduling_level];

        // Else, just send it to the highest available priority
        } else {

          while (!actual_allocation[highestFreeLevel]) --highestFreeLevel;

          curr_w->l->next_scheduling_level = highestFreeLevel;
          --actual_allocation[highestFreeLevel];
        }
      }

      for (int i = std::max(0, gstate->P - curr_round_robin_workers); i < gstate->P; i++) {
        if (gstate->workers[i]->l->scheduling_level == gstate->workers[i]->l->next_scheduling_level) {
          if (firstTimeAtRRLevel[i]) {
            firstTimeAtRRLevel[i] = false;
          } else {
            gstate->workers[i]->l->next_scheduling_level = nextRoundRobinLevel[i];
            nextRoundRobinLevel[i] = (nextRoundRobinLevel[i] + 1) % (__cilk_highestSchedulingLevel+1);
            firstTimeAtRRLevel[i] = true;
          }
        }
      }

      int next_assigned_level = __cilk_highestSchedulingLevel;
      for (int i = gstate->P - curr_round_robin_workers - 1; i >= 0 && i >= gstate->P - curr_reserved_or_rr_workers; i--) {
        gstate->workers[i]->l->next_scheduling_level = next_assigned_level;
        next_assigned_level = next_assigned_level - 1;
        if (next_assigned_level < 0) next_assigned_level = __cilk_highestSchedulingLevel;
      }

      __asm__ volatile ("" ::: "memory");

      gstate->scheduling_level_quantum = quantum_end_time;

      //__asm__ volatile ("" ::: "memory");

      __atomic_store_n(&gstate->reading_idle_stats, false, __ATOMIC_RELEASE);
      //gstate->reading_idle_stats = false;

      //__asm__ volatile ("" ::: "memory");
      //std::this_thread::sleep_for(std::chrono::microseconds(sleepTime));
      //if (desire[3] != 0.0) printf("Desire of 3: %lf (allocated at least %d)\n", desire[3], allocation[3]);
      std::this_thread::sleep_for(std::chrono::microseconds(curr_cilk_quantum_length_us));
    }

    printf("Avg quantum length (tsc ticks): %lg\n", avgL);

    delete [] desire;
    delete [] allocation;
    delete [] actual_allocation;
    delete [] utilization;
    delete [] maxUtilization;
    delete [] nextRoundRobinLevel;
    delete [] firstTimeAtRRLevel;
  }

  return NULL;
}

// rdtsc support
#include <x86intrin.h>

int64_t cilk_prio_get_current_time_tsc_ticks() {
  //unsigned int dummy;
  //return __rdtscp(&dummy);
  // we are okay if imprecise due to instn reordering
  // so we don't need rdtscp
  return __rdtsc();
}

}
