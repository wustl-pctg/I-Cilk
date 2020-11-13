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

/**
 * Linux kernel-assisted timing library -- provides high-precision time
 * measurements for the execution time of your algorithms.
 *
 * You shouldn't need to modify this file. More importantly, you should not
 * depend on any modifications you make here, as we will replace it with a
 * fresh copy when we test your code.
 **/

#include "common/ktiming.h"

#include <math.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//#define USEC_TO_SEC(x) ((double)x*1.0e-9)
#define USEC_TO_SEC(x) ((double)x*1.0e-3)

#ifndef USE_PRIO_SCHEDULER_TIME
clockmark_t ktiming_getmark(void) {
    struct timespec temp;
    uint64_t nanos;

    int stat = clock_gettime(CLOCK_MONOTONIC , &temp);
    if (stat != 0) {
        perror("ktiming_getmark()");
        exit(-1);
    }
    nanos = temp.tv_nsec;
    nanos += ((uint64_t)temp.tv_sec) * 1000 * 1000 * 1000;
    return nanos;
}
#endif

clockmark_t ktiming_diff_usec(const clockmark_t* const 
                           start, const clockmark_t* const end) {
    return *end - *start;
}

double ktiming_diff_sec(const clockmark_t* const start, 
                       const clockmark_t* const end) {
    return ((double)ktiming_diff_usec(start, end)) / 1000000000.0f;
}

static void
calc_statistics(uint64_t *usec_elapsed, int size, double *ave, double *std_dev, double *max, double *min, double *per50, double *per90, double *per95, double *per99) {
    int i;
    uint64_t total = 0;
    double dev_sq_sum = 0;
    *std_dev = 0;
    *max = DBL_MIN;
    *min = DBL_MAX;
    int per50idx = ceil(size*0.5) - 1;
    int per90idx = ceil(size*0.90) - 1;
    int per95idx = ceil(size*0.95) - 1;
    int per99idx = ceil(size*0.99) - 1;
    
    for (i = 0; i < size; i++) {
        total += usec_elapsed[i];
        *max = (*max > usec_elapsed[i] ? *max : usec_elapsed[i]);
        *min = (*min < usec_elapsed[i] ? *min : usec_elapsed[i]);
        if (i == per50idx) *per50 = usec_elapsed[i];
        if (i == per90idx) *per90 = usec_elapsed[i];
        if (i == per95idx) *per95 = usec_elapsed[i];
        if (i == per99idx) *per99 = usec_elapsed[i];
    }
    *ave = total / size;

    if( size > 1 ) {
        for (i = 0; i < size; i++) {
            dev_sq_sum += ( (*ave - (double)usec_elapsed[i]) * 
                            (*ave - (double)usec_elapsed[i]) );
        }
        *std_dev = sqrt(dev_sq_sum / (size-1));
    }
}

static void
calc_statisticsDbl(double *usec_elapsed, int size, double *ave, double *std_dev, double *max, double *min, double *per50, double *per90, double *per95, double *per99) {
    int i;
    double total = 0;
    double dev_sq_sum = 0;
    *std_dev = 0;
    *max = DBL_MIN;
    *min = DBL_MAX;
    int per50idx = ceil(size*0.5) - 1;
    int per90idx = ceil(size*0.90) - 1;
    int per95idx = ceil(size*0.95) - 1;
    int per99idx = ceil(size*0.99) - 1;
    
    for (i = 0; i < size; i++) {
        total += usec_elapsed[i];
        *max = (*max > usec_elapsed[i] ? *max : usec_elapsed[i]);
        *min = (*min < usec_elapsed[i] ? *min : usec_elapsed[i]);
        if (i == per50idx) *per50 = usec_elapsed[i];
        if (i == per90idx) *per90 = usec_elapsed[i];
        if (i == per95idx) *per95 = usec_elapsed[i];
        if (i == per99idx) *per99 = usec_elapsed[i];
    }
    *ave = total / size;

    if( size > 1 ) {
        for (i = 0; i < size; i++) {
            dev_sq_sum += ( (*ave - (double)usec_elapsed[i]) * 
                            (*ave - (double)usec_elapsed[i]) );
        }
        *std_dev = sqrt(dev_sq_sum / (size-1));
    }
}

static void 
print_runtime_helper(uint64_t *usec_elapsed, int size, int summary) {

    int i; 
    double ave, std_dev = 0;
    double maxTime = DBL_MIN;
    double minTime = DBL_MAX;
    double per50, per90, per95, per99;

    if (!summary) {
        for (i = 0; i < size; i++) {
            printf("Running time %d: %gs\n", (i + 1), USEC_TO_SEC(usec_elapsed[i]));
        }
    }
    
    calc_statistics(usec_elapsed, size, &ave, &std_dev, &maxTime, &minTime, &per50, &per90, &per95, &per99);

    printf("Running time average: %g us\n", USEC_TO_SEC(ave));
    printf("Max: %g us\n", USEC_TO_SEC(maxTime));
    printf("Min: %g us\n", USEC_TO_SEC(minTime));
    printf("50%%: %g us\n", USEC_TO_SEC(per50));
    printf("90%%: %g us\n", USEC_TO_SEC(per90));
    printf("95%%: %g us\n", USEC_TO_SEC(per95));
    printf("99%%: %g us\n", USEC_TO_SEC(per99));

    if( std_dev != 0 ) {
        printf( "Std. dev: %g us (%2.3f%%)\n", 
                USEC_TO_SEC(std_dev), 100.0*std_dev/ave );
    }
}

void print_runtime(uint64_t *tm_elapsed, int size) {
    print_runtime_helper(tm_elapsed, size, 0);
}

void print_runtime_summary(uint64_t *tm_elapsed, int size) {
    print_runtime_helper(tm_elapsed, size, 1);
}

static void 
print_runtime_helperDbl(double *usec_elapsed, int size, int summary) {

    int i; 
    double ave, std_dev = 0;
    double maxTime = DBL_MIN;
    double minTime = DBL_MAX;
    double per50, per90, per95, per99;

    if (!summary) {
        for (i = 0; i < size; i++) {
            printf("Running time %d: %gs\n", (i + 1), USEC_TO_SEC(usec_elapsed[i]));
        }
    }
    
    calc_statisticsDbl(usec_elapsed, size, &ave, &std_dev, &maxTime, &minTime, &per50, &per90, &per95, &per99);

    printf("Running time average: %g us\n", USEC_TO_SEC(ave));
    printf("Max: %lf us\n", USEC_TO_SEC(maxTime));
    printf("Min: %lf us\n", USEC_TO_SEC(minTime));
    printf("50%%: %lf us\n", USEC_TO_SEC(per50));
    printf("90%%: %lf us\n", USEC_TO_SEC(per90));
    printf("95%%: %lf us\n", USEC_TO_SEC(per95));
    printf("99%%: %lf us\n", USEC_TO_SEC(per99));

    if( std_dev != 0 ) {
        printf( "Std. dev: %g us (%2.3f%%)\n", 
                USEC_TO_SEC(std_dev), 100.0*std_dev/ave );
    }
}

void print_runtime_summaryDbl(double *tm_elapsed, int size) {
    print_runtime_helperDbl(tm_elapsed, size, 1);
}

void print_csv_summaryDbl(double *tm_elapsed, int size, const char *const prefix) {
  double ave, std_dev = 0;
  double maxTime = DBL_MIN;
  double minTime = DBL_MAX;
  double per50, per90, per95, per99;
  
  calc_statisticsDbl(tm_elapsed, size, &ave, &std_dev, &maxTime, &minTime, &per50, &per90, &per95, &per99);

  if (prefix[strlen(prefix)-1] == ',' || strcmp(prefix, "") == 0) {
    printf("%s ", prefix);
  } else {
    printf("%s, ", prefix);
  }
  printf("%g, %g, %g, %g, %g, %g, %g, %g, %g\n", USEC_TO_SEC(ave), USEC_TO_SEC(maxTime), USEC_TO_SEC(minTime), USEC_TO_SEC(std_dev), 100.0*std_dev/ave, USEC_TO_SEC(per50), USEC_TO_SEC(per90), USEC_TO_SEC(per95), USEC_TO_SEC(per99));
}

void print_csv_summary(uint64_t *tm_elapsed, int size, const char *const prefix) {
  double ave, std_dev = 0;
  double maxTime = DBL_MIN;
  double minTime = DBL_MAX;
  double per50, per90, per95, per99;
  
  calc_statistics(tm_elapsed, size, &ave, &std_dev, &maxTime, &minTime, &per50, &per90, &per95, &per99);

  if (prefix[strlen(prefix)-1] == ',' || strcmp(prefix, "") == 0) {
    printf("%s ", prefix);
  } else {
    printf("%s, ", prefix);
  }
  printf("%g, %g, %g, %g, %g, %g, %g, %g, %g\n", USEC_TO_SEC(ave), USEC_TO_SEC(maxTime), USEC_TO_SEC(minTime), USEC_TO_SEC(std_dev), 100.0*std_dev/ave, USEC_TO_SEC(per50), USEC_TO_SEC(per90), USEC_TO_SEC(per95), USEC_TO_SEC(per99));
}
