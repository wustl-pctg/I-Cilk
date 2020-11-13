// Stat related functions, definitions, etc.

#ifndef _STAT_H_
#define _STAT_H_

#include "util.h"

typedef struct {
  long long unsigned time;		/* time to run the trial */
  double memutils;		/* % of memory allocated that is used to run the trial */
  long long unsigned* barrierEnds;	/* the time each thread reaches the barrier */
  BarrierSummary barrierGaps;	/* the ratio of max finisher to median finisher and max finisher to min finisher */
  double* startTemp;		/* the starting temps of each core */
  double* endTemp;		/* the ending temps of each core */
  double avgCoolWait;		/* average time to cool down if requested enforcetemps */
} PerTrialInfo;

void printPTI(FILE* f, PerTrialInfo* p);

#define statAdrOf(base, fld, type)		(*((type**)( ((char*)base)+statOffset(fld) )))
#define statOffset(fld) 			((int)(((char*)&(trialData->fld)) - (char*)(&(trialData->time))))
#define baseOffset2Data(base, offset, type)	(*(type*)(((char*)(base))+offset))

void trimData(int n, int offset, PerTrialInfo* info, long long unsigned* trimmedTimes);

double getMedian(long long unsigned* trialTimes, int trialNumber);
double getMean(long long unsigned* trialTimes, int trialNumber);
double getSD(long long unsigned* trialTimes, int trialNumber);
double getMin(long long unsigned* trialTimes, int trialNumber);
double getMax(long long unsigned* trialTimes, int trialNumber);

double getMeanD(double* list, int n);
double getMinD(double* list, int n);
double getMaxD(double* list, int n);

double getMedianL(PerTrialInfo* trialTimes, int offset, int trialNumber);
double getMeanL(PerTrialInfo* trialTimes, int offset, int trialNumber);
double getSDL(PerTrialInfo* trialTimes, int offset, int trialNumber);
double getMinL(PerTrialInfo* trialTimes, int offset, int trialNumber);
double getMaxL(PerTrialInfo* trialTimes, int offset, int trialNumber);

double getMedianFloat(PerTrialInfo* trialUtils, int offset, int trialNumber);
double getMeanFloat(PerTrialInfo * trialUtils, int offset, int trialNumber);
double getSDFloat(PerTrialInfo* trialUtils, int offset, int trialNumber);
double getMinFloat(PerTrialInfo* trialUtils, int offset, int trialNumber);
double getMaxFloat(PerTrialInfo* trialUtils, int offset, int trialNumber);

extern PerTrialInfo* trialData;		/* all the data for every trial */
extern PerTrialInfo* tdp;		/* pointer to PerTrialInfo for this time tick */

#endif
