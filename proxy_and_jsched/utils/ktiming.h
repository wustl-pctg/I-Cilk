/**
 * Copyright (c) 2012 MIT License by 6.172 Staff
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 **/

#ifndef _KTIMING_H_
#define _KTIMING_H_

#include <inttypes.h>

//#define USE_PRIO_SCHEDULER_TIME

#ifdef USE_PRIO_SCHEDULER_TIME
  typedef int64_t clockmark_t;
  #ifdef __cplusplus
    extern "C" int64_t cilk_prio_get_current_time_ns();
  #else
    extern int64_t cilk_priority_get_current_time_ns();
  #endif
  #define ktiming_getmark   cilk_prio_get_current_time_ns
#else
  typedef uint64_t clockmark_t;
  clockmark_t ktiming_getmark(void);
#endif

clockmark_t 
ktiming_diff_usec(const clockmark_t* const start, const clockmark_t* const end);
double
ktiming_diff_sec(const clockmark_t* const start, const clockmark_t* const end);
void print_runtime(uint64_t *tm_elapsed, int size); 
void print_runtime_summary(uint64_t *tm_elapsed, int size); 
void print_csv_summary(uint64_t *tm_elapsed, int size, const char *const prefix);

void print_runtime_summaryDbl(double *tm_elapsed, int size); 
void print_csv_summaryDbl(double *tm_elapsed, int size, const char *const prefix);
void print_csv(uint64_t *tm_elapsed, int size, const char *const prefix);
void print_csvDbl(double *tm_elapsed, int size, const char *const prefix);
#endif  // _KTIMING_H_

