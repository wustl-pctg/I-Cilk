#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <malloc.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "timing.h"
#include "stat.h"
#include "util.h"

const char* progname;

void
dieOnErrno(const char* fn, int ln, int en, const char* msg, ...)
{
    va_list ap;

    va_start(ap, msg);
    fprintf(stderr, "%s:%d:", __FILE__, __LINE__);
    vfprintf(stderr, msg, ap);
    va_end (ap);
    fprintf(stderr, " %d:%s\n", en, strerror(en));
    exit(-1);
}

  
void
die(const char* fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    fprintf(stderr, "%s: ", progname);
    vfprintf(stderr, fmt, ap);
    va_end (ap);
    fprintf(stderr, "\n");
    exit(-1);
}

////////////////////////////////////////////////////////////////
// basic helper functions

void*
myCalloc(size_t nmemb, size_t size, const char* fname, const int ln)
{
  void* p = calloc(nmemb, size);
  if (p == NULL) die("Failed to allocate memory at %s:%d", fname, ln);
  return p;
}

void 
semWait(sem_t *sem) {
  while (sem_wait(sem) == -1) {
    if (errno == EINTR) continue;
    // some other error
    errdie("Semaphore wait failure");
  }
}

void 
semPost(sem_t* sem) {
  if (sem_post(sem) == 0) return;
  errdie("semaphore post failure");
}

void
initBarrierN(Barrier* b, int n) {
  int s = pthread_barrier_init(&b->barrier, NULL, n);
  if (s) errdie("Can't initialize barrier");
  b->n = n;
  b->endWait = mycalloc(n, sizeof(long long unsigned));
}

void
myBarrier(Barrier* b, int tid) {
  TimingStruct timer;
  startTimer(&timer);
  pthread_barrier_wait(&b->barrier);
  b->endWait[tid] = endTimer(&timer);
}

void
getBTsummary(Barrier* b, nanoseconds* tp, BarrierSummary* sp) {
  // copy over end times
  for (int i=0; i<b->n; i++) {
    tp[i] = b->endWait[i];
  }
  // calculate summary info
  if (b->n < 2) {
    sp->medgap = sp->maxgap = 0;
    return;
  }
  double median = getMedian(b->endWait, b->n);
  double min = getMin(b->endWait, b->n);
  double max = getMax(b->endWait, b->n);
  sp->maxgap = (max-min)/max;
  sp->medgap = (max-median)/max;
  return;
}

void
showWaiting(Barrier* b, const char* msg) {
  printf("%s:", msg);
  for (int i=0; i<b->n; i++) printf("\t%6llu", b->endWait[i]);
  printf("\n");
}

////////////////////////////////////////////////////////////////
// stat functions

#define iAtOffset(i, offset) (((char*)(info+i))+offset)
#define LLiAtOffset(i, offset) (*(nanoseconds*)(iAtOffset(i, offset)))
void
trimData(int n, int offset, PerTrialInfo* info, nanoseconds* trimmedTimes) {
  nanoseconds min = *(nanoseconds*)(iAtOffset(0, offset));
  nanoseconds max = min;
  assert(n > 2);
  // find min and max
  for (int i=0; i<n; i++) {
    if (LLiAtOffset(i, offset) < min) min = LLiAtOffset(i, offset);
    if (LLiAtOffset(i, offset) > max) max = LLiAtOffset(i, offset);
  }
  // now copy all but one min and one max
  int mincopy = 1;
  int maxcopy = 1;
  int x = 0;
  for (int i=0; i<n; i++) {
    if (mincopy && (LLiAtOffset(i, offset) == min)) {
      mincopy = 0;
      continue;
    }
    if (maxcopy && (LLiAtOffset(i, offset) == max)) {
      maxcopy = 0;
      continue;
    }
    trimmedTimes[x++] = LLiAtOffset(i, offset);
  }
}


static int nanocomp(const void* a, const void *b) {
  return *(nanoseconds*)b - *(nanoseconds*)a;
}

static int dblcomp(const void* a, const void *b) {
  return *(double*)b - *(double*)a;
}

double
getMedian(nanoseconds* trialTimes, int trialNumber)
{
  nanoseconds* tt = calloc(trialNumber, sizeof(nanoseconds));//mycalloc(trialNumber, sizeof(nanoseconds));
  memcpy(tt, trialTimes, trialNumber*sizeof(nanoseconds));
  qsort(tt, trialNumber, sizeof(nanoseconds), nanocomp);
  nanoseconds median;
  if (trialNumber & 1) median = tt[trialNumber >> 1];
  else median = (tt[(trialNumber-1) >> 1] + tt[((trialNumber-1) >> 1)+1])>>1;
  free(tt);
  return median;
}

double
getMean(nanoseconds* trialTimes, int trialNumber)
{
  double total = 0.0;
  for (int x = 0; x<trialNumber; x++) {
    total += (double)trialTimes[x];
  }
  return total/(double)trialNumber;
}

double
getSD(nanoseconds* trialTimes, int trialNumber)
{
  double sum = 0.0;
  double mean;
  double sd = 0.0;
  int i;

  for(i=0; i<trialNumber; i++) {
    sum += trialTimes[i];
  }

  mean = sum/(double)trialNumber;

  for(i=0; i<trialNumber; i++)
    sd += pow(trialTimes[i] - mean, 2);

  return sqrt(sd/trialNumber);
}

double 
getMin(nanoseconds* trialTimes, int trialNumber) {
  double m = trialTimes[0];
  for(int i=0; i<trialNumber; i++)
    if (m > trialTimes[i]) m = trialTimes[i];
  return m;
}


double 
getMax(nanoseconds* trialTimes, int trialNumber) {
  double m = trialTimes[0];
  for(int i=0; i<trialNumber; i++)
    if (m < trialTimes[i]) m = trialTimes[i];
  return m;
}

void* gatherAndSort(PerTrialInfo* base, int offset, int datasize, int n, int (*compfunc)(const void* a, const void *b)) {
  assert(datasize == sizeof(double)); /* assuming doing it only for long long int and double */
  double* data = mycalloc(n+1, datasize);
  for (int i=0; i<n; i++) {
    data[i] = *(double*)(((char*)(base+i))+offset);
  }
  qsort(data, n, datasize, compfunc);
  return data;
}

double
getMeanD(double* list, int n)
{
  double total = 0.0;
  for (int x = 0; x<n; x++) {
    total += list[x];
  }
  return total/(double)n;
}


double 
getMinD(double* list, int n) {
  double m = list[0];
  for(int i=0; i<n; i++)
    if (m > list[i]) m = list[i];
  return m;
}


double 
getMaxD(double* list, int n) {
  double m = list[0];
  for(int i=0; i<n; i++)
    if (m < list[i]) m = list[i];
  return m;
}


////////////////////////////////////////////////////////////////
// long long (inside PerTrialInfo)

double
getMedianL(PerTrialInfo* base, int offset, int n)
{
  nanoseconds* tt = (nanoseconds*)gatherAndSort(base, offset, sizeof(nanoseconds), n, nanocomp);
  nanoseconds median;
  if (n & 1) median = tt[n >> 1];
  else median = (tt[(n-1) >> 1] + tt[((n-1) >> 1)+1])>>1;
  free(tt);
  return median;
}

double
getMeanL(PerTrialInfo* base, int offset, int trialNumber)
{
  double total = 0.0;
  for (int x = 0; x<trialNumber; x++) {
    total += (double)baseOffset2Data(base+x, offset, nanoseconds);
  }
  return total/(double)trialNumber;
}

 double
getSDL(PerTrialInfo* base, int offset, int trialNumber)
{
  double sum = 0.0;
  double mean;
  double sd = 0.0;
  int i;

  for(i=0; i<trialNumber; i++) {
    sum += (double)baseOffset2Data(base+i, offset, nanoseconds);
  }

  mean = sum/(double)trialNumber;

  for(i=0; i<trialNumber; i++)
    sd += pow((double)baseOffset2Data(base+i, offset, nanoseconds) - mean, 2);

  return sqrt(sd/trialNumber);
}

double 
getMinL(PerTrialInfo* base, int offset, int trialNumber) {
  double m = baseOffset2Data(base, offset, nanoseconds);
  for(int i=0; i<trialNumber; i++)
    if (m > baseOffset2Data(base+i, offset, nanoseconds)) m = baseOffset2Data(base+i, offset, nanoseconds);
  return m;
}


double 
getMaxL(PerTrialInfo* base, int offset, int trialNumber) {
  double m = baseOffset2Data(base, offset, nanoseconds);
  for(int i=0; i<trialNumber; i++)
    if (m < baseOffset2Data(base+i, offset, nanoseconds)) m = baseOffset2Data(base+i, offset, nanoseconds);
  return m;
}

////////////////////////////////////////////////////////////////
// double (inside PerTrialInfo)

double
getMedianFloat(PerTrialInfo* base, int offset, int n)
{
  double* tt = (double*)gatherAndSort(base, offset, sizeof(double), n, dblcomp);
  double median;
  if (n & 1) median = tt[n >> 1];
  else median = (tt[(n-1) >> 1] + tt[((n-1) >> 1)+1])/2.0;
  free(tt);
  return median;
}

double
getMeanFloat(PerTrialInfo* base, int offset, int trialNumber)
{
  double total = 0.0;
  for (int x = 0; x<trialNumber; x++) {
    total += baseOffset2Data(base+x, offset, double);
  }
  return total/(double)trialNumber;
}

double
getSDFloat(PerTrialInfo* base, int offset, int trialNumber)
{
  double sum = 0.0;
  double mean;
  double sd = 0.0;
  int i;

  for(i=0; i<trialNumber; i++) {
    sum += baseOffset2Data(base+i, offset, double);
  }

  mean = sum/(double)trialNumber;

  for(i=0; i<trialNumber; i++)
    sd += pow(baseOffset2Data(base+i, offset, double) - mean, 2);

  return sqrt(sd/trialNumber);
}

double 
getMinFloat(PerTrialInfo* base, int offset, int trialNumber) {
  double m = baseOffset2Data(base, offset, double);
  for(int i=0; i<trialNumber; i++) {
    double val = baseOffset2Data(base+i, offset, double);
    if (m > val) m = val;
  }
  return m;
}


double 
getMaxFloat(PerTrialInfo* base, int offset, int trialNumber) {
  double m = baseOffset2Data(base, offset, double);
  for(int i=0; i<trialNumber; i++) {
    double val = baseOffset2Data(base+i, offset, double);
    if (m < val) m = val;
  }
  return m;
}

