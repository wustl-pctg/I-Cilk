// try abstract the timing function we are going to use.  TimingStruct
// will always point to something to keep track of start.  endTimer
// will always return number of elapsed nanoseconds.

#ifndef _TIMING_H_
#define _TIMING_H_

#include <time.h>

typedef long long unsigned nanoseconds;
typedef struct timespec TimingStruct;

void startTimer(TimingStruct* ts);
nanoseconds endTimer(TimingStruct* ts);

#endif
