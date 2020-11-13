#include <stdio.h>
#include "timing.h"
#include "util.h"

extern int verbose;

////////////////////////////////////////////////////////////////
// first version: Use clock_gettime, clock_getres
//

#define clockID CLOCK_MONOTONIC

void
startTimer(TimingStruct* ts) {
  int s = clock_gettime(clockID, ts);
  if (s) errdie("Could not get time at start");
}

nanoseconds
endTimer(TimingStruct* ts) {
  struct timespec end;
  struct timespec res;
  
  int s = clock_gettime(clockID, &end);
  if (s) errdie("Could not get time at end");

  time_t secs = end.tv_sec - ts->tv_sec;
  long nano = end.tv_nsec - ts->tv_nsec;

  s = clock_getres(clockID, &res);
  if (s) errdie("Could not get resolution");
  
  if (verbose>1) fprintf(stderr, 
		       "%ld %ld -> %ld %ld = %ld %ld by %ld %ld: %lu\n", 
		       ts->tv_sec, ts->tv_nsec, end.tv_sec, end.tv_nsec, 
		       secs, nano, res.tv_sec, res.tv_nsec, ((long)secs)*1000000000 + nano);
  return ((long)secs)*1000000000L + nano;
}

