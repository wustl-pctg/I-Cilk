//#include "dist.h"
#include "util.h"
#include "math.h"
#include "arg.h"

#define VERSION "0.1"
static const gsl_rng_type * T;
static int useEnv = 0;
static double initAlpha;
static double initBeta;

void
postArgs(void)
{
}

static ArgOption args[] = {
  // Kind, 	  Method,		name,	    reqd,  variable,		help
  { KindOption,   Set, 		"--rand:useenv",0, &useEnv, 		"use GSL env vars to define random number generator" },
  { KindEnd }

};
static ArgDefs argp = { args, "prob dist library", VERSION, postArgs };

void* 
getProbDistArgParsing(void)
{
  return &argp;
}

// initialize prob dists, called once from main
void
initProbDist(void)
{
  if (useEnv) {
    gsl_rng_env_setup();
    T = gsl_rng_default;
  } else {
    T = gsl_rng_mt19937;
  }
}

// destory and free memory
void 
freeRandGenerator(ProbDist* pd)
{
  gsl_rng_free(pd->r);
  free(pd);
}

// create an alpha-beta prob dist for a particular thread
ProbDist* 
makeRandGenerator(double a, double b)
{
  ProbDist* pd = mycalloc(1, sizeof(ProbDist));
  pd->alpha = a;
  pd->beta = b;
  pd->r = gsl_rng_alloc(T);
  return pd;
}

long int 
getRandLong(ProbDist* p, long range)
{
  return (long int)round((double)range * gsl_ran_beta(p->r, p->alpha, p->beta));
}

