#ifndef _UTIL_H_
#define _UTIL_H_

#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <stdio.h>
// Basic error reporting


void dieOnErrno(const char* fn, int ln, int en, const char* msg, ...);

void die(const char* fmt, ...);
#define errdie(msg, args...) dieOnErrno(__FILE__, __LINE__, errno, msg, ##args)


extern const char* progname;

// basic memory
void* myCalloc(size_t nmemb, size_t size, const char* fname, const int ln);
#define mycalloc(x, y) myCalloc((x), (y), __FILE__, __LINE__)


// basic pthread related functions

void semWait(sem_t *sem);
void semPost(sem_t* sem);

typedef struct barrier_struct {
  pthread_barrier_t barrier;
  long long unsigned* endWait;
  int n;
} Barrier;

typedef struct _barrier_summary {
  double maxgap;
  double medgap;
} BarrierSummary;


void myBarrier(Barrier* b, int t);
void initBarrierN(Barrier* b, int n);
void showWaiting(Barrier* b, const char* msg);
void getBTsummary(Barrier* b, long long unsigned* tp, BarrierSummary* sp);

#define initBarrier(b) initBarrierN(b, nthreads);

// stats

#endif
