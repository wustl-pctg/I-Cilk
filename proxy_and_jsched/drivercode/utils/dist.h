#ifndef _DIST_H_
#define _DIST_H_

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

typedef struct pdist ProbDist;

struct pdist {
  gsl_rng *r;			/* gsl struct */
  double alpha;
  double beta;
};

ProbDist* makeRandGenerator(double a, double b);
void freeRandGenerator(ProbDist* pd);

long int getRandLong(ProbDist* p, long range);
void initProbDist(void);

// this returns an ArgDefs*, but make it void so we can easuly reuse this without arg.h
void* getProbDistArgParsing(void);

#endif
