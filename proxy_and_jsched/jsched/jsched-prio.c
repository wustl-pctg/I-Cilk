#include <cilk/cilk_priority.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/timerfd.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <netdb.h>
#include <sys/un.h>
#include <fcntl.h>
#include <math.h>
#include "../utils/arg.h"
#include "../utils/util.h"
#include "../utils/timing.h"
#include "../utils/ktiming.h"

#define SW_N 1024
#define SW_BSIZE 4
#define SIZE_OF_ALPHABETS 4

#define FIB_N 36

#define MM_N 1024
#define MM_POWER 6

#define SORT_N 11000000

#define numFuns 4
char fun_name[numFuns][8]={
  "SW", //low
  "FIB", //medhigh
  "MM", //high
  "SORT" //medlow
};

int order[4] = {2, 1, 3, 0};
//priorty: f0P(sw)<f03(sort)<f01(fib)<f02(mm)<RunP(loop scheduling)
CilkDeclareNewPriority(LowP, cilk::Low);
CilkDeclareNewPriority(MedLowP, LowP);
CilkDeclareNewPriority(MedHighP, MedLowP);
CilkDeclareNewPriority(HighP, MedHighP);
CilkDeclareNewPriority(RunP, HighP);
typedef LowP f0P;
typedef MedHighP f1P;
typedef HighP f2P;
typedef MedLowP f3P;


#define Version "0.1"



#define us 1000000
#define ns (1000000000UL)
long ns2=ns;

//SW_STUFF
#define BLOCK_IND_TO_IND(i) (i << base_case_log)
#define NUM_BLOCKS(n) (n >> base_case_log)

static inline int max(int a, int b) { return (a < b) ? b : a; }
static inline int ilog2(int x) { return 32 - __builtin_clz(x) - 1; }
int base_case_log=0;

//MM_STUFF
#define REAL int
static int BASE_CASE; //the base case of the computation (2*POWER)
static int POWER; //the power of two the base case is based on
static const unsigned int Q[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF};
static const unsigned int S[] = {1, 2, 4, 8};

//SORT_STUFF
typedef long ELM;
#define KILO 1024
#define MERGESIZE KILO
#define QUICKSIZE KILO
#define INSERTIONSIZE 20
static unsigned long rand_nxt = 0;

#define swap_indices(a, b)			\
  {						\
    ELM *tmp;					\
    tmp = a;					\
    a = b;					\
    b = tmp;					\
  }
#define swap(a, b)				\
  {						\
    ELM tmp;					\
    tmp = a;					\
    a = b;					\
    b = tmp;					\
  }

static inline void my_srand(unsigned long seed) {

  rand_nxt = seed;
}

static inline unsigned long my_rand(void) {

  rand_nxt = rand_nxt * 1103515245 + 12345;
  return rand_nxt;
}

void scramble_array(ELM *arr, unsigned long size) {

  unsigned long i;
  unsigned long j;

  for (i = 0; i < size; ++i) {
    j = my_rand();
    j = j % size;
    long temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;

  }
}

void fill_array(ELM *arr, unsigned long size) {

  unsigned long i;


  /* first, fill with integers 1..size */
  for (i = 0; i < size; ++i) {
    arr[i] = i;
  }

  /* then, scramble randomly */
  scramble_array(arr, size);
}



//PRIORITY HEADERS
CilkPrioCommandPrototype(int, wave_sw_with_futures,int*, char*, char*, int); //sw
CilkPrioCommandPrototype(void, recursive_process_sw_tiles, int*, char*, char*, int, int, int, int); //sw recursive part
CilkPrioCommandPrototype(int, fib, int); //fib
CilkPrioCommandPrototype(void,mat_mul_par,const REAL *, const REAL *,REAL*, int); //mm
CilkPrioCommandPrototype(void, cilkmerge,ELM*, ELM*,ELM*, ELM*, ELM*); //sort
CilkPrioCommandPrototype(void, cilksort,ELM*, ELM*, long);  //sort
CilkPrioCommandPrototype(int, fun0,int, struct timespec*, struct timespec *, cilk::pfuture<int, f0P>*, int*, char*, char*, int); //sw wrapper
CilkPrioCommandPrototype(int, fun1,int, struct timespec*, struct timespec *, cilk::pfuture<int, f1P>*, int); //fib wrapper
CilkPrioCommandPrototype(int, fun2,int, struct timespec*, struct timespec *, cilk::pfuture<int, f2P>*, REAL*, REAL*, REAL*, int); //mm wrapper
CilkPrioCommandPrototype(int, fun3,int, struct timespec*, struct timespec *, cilk::pfuture<int, f3P>*, ELM*, ELM*, long); //sort wrapper
CilkPrioCommandPrototype(int, runner,int, struct timespec *, struct timespec*); //job scheduler


//futs for each function 
cilk::pfuture<int, f0P>* f_futs0=NULL;
cilk::pfuture<int, f1P>* f_futs1=NULL;
cilk::pfuture<int, f2P>* f_futs2=NULL;
cilk::pfuture<int, f3P>* f_futs3=NULL;

int verbose=0; //verbose (bool)
double fWait[numFuns]={0}; //period for each function
long duration=0; //total duration to run for (seconds)
long requests=0; //amount of items for timing array
int rseed=0; //rand number seed
pthread_barrier_t sBarrier; //barrier so that scheduling doesnt start till all functions ready

//fd for outputing util/quantlen info
extern FILE* utilOutput;
extern bool closeUtilOutput;


//cilk variables
int cilk_quantum_length_us ;
double cilk_rho ;
double cilk_util_bound ;
double cilk_init_desire ;
int cilk_rr_worker_count ;
int cilk_reserved_w_per_lvl ;

//denominator for poisson scheduling
double den=((double)RAND_MAX)+1.0;

static ArgOption args[] = {
  // Kind,        Type,   name,         reqd, variable,                 help
  { KindOption,   Integer,"-v",            0, &verbose,                 "Turn on verbosity (0-2)" },
  { KindOption,   Double, "-f0",           0, &fWait[0],                "Calls to Smith-Waternman per seconds" },
  { KindOption,   Double, "-f1",           0, &fWait[1],                "Calls to Fib per second" },
  { KindOption,   Double, "-f2",           0, &fWait[2],                "Calls to Matrix-Multiply per second" },
  { KindOption,   Double, "-f3",           0, &fWait[3],                "Calls to Sort per second" },
  { KindOption,   Integer,"--seed",        0, &rseed,                   "Random number seed" },
  { KindOption,   Integer,"--duration",    0, &duration,                "Time in seconds to run" },
  { KindOption,   Integer,"--quantlen",    0, &cilk_quantum_length_us,  "Set cilk quantum length in us" },
  { KindOption,   Double, "--cilkrho",     0, &cilk_rho,                "Set cilk rho value" },
  { KindOption,   Double, "--cilkutil",    0, &cilk_util_bound,         "Set cilk util bound" },
  { KindOption,   Double, "--cilkinit",    0, &cilk_init_desire,        "Set cilk initial desire" },
  { KindOption,   Integer,"--cilkWrks",    0, &cilk_rr_worker_count,    "Set cilk round robin worker count" },
  { KindOption,   Integer,"--cilkres",     0, &cilk_reserved_w_per_lvl, "Set cilk reserverd work per level" },
  { KindHelp,     Help,    "-h" },
  { KindEnd }
};
static ArgDefs argp = { args, "Job Scheduler Priority", Version, NULL };



//turns timespec to us
//t: timespec to convert
suseconds_t to_usecs(struct timespec t) {
  return (t.tv_sec * ns + t.tv_nsec)/1000;
}

suseconds_t to_nsecs(struct timespec t) {
  return (t.tv_sec * ns + t.tv_nsec);
}
suseconds_t format_ts(struct timespec t) {
  return to_usecs(t);
}

//returns difference between two timespecs in us
//t1: timespec to subtract from
//t2: timespec whose value is subtracted
long difftimespecs(struct timespec t1, struct timespec t2) {
  return (format_ts(t1) - format_ts(t2));
}

long difftimespecs_ns(struct timespec t1, struct timespec t2) {
  return (to_nsecs(t1) - to_nsecs(t2));
}


//SW_FUNCTIONS
__attribute__((unused)) static
void gen_rand_string(char * s, int s_length, int range) {
  for(int i = 0; i < s_length; ++i ) {
    s[i] = (char)(rand() % range + 97);
  }
}


static int 
process_sw_tile(int *stor, char *a, char *b, int n, int iB, int jB) {

  int bSize = 1 << base_case_log;

  for(int i = 0; i < bSize; i++) {
    for(int j = 0; j < bSize; j++) {

      int i_ind = BLOCK_IND_TO_IND(iB) + i;
      int j_ind = BLOCK_IND_TO_IND(jB) + j;

      if(i_ind == 0 || j_ind == 0) {
        stor[i_ind*n + j_ind] = 0;
      } else {
        int max_val = 0;
        for(int k = 1; k < i_ind; k++) {
          max_val = max(stor[k*n + j_ind]-(i_ind-k), max_val);
        }
        for(int k = 1; k < j_ind; k++) {
          max_val = max(stor[i_ind*n + k]-(j_ind-k), max_val);
        }
        stor[i_ind*n + j_ind] = 
          max( stor[(i_ind-1)*n + (j_ind-1)] + (a[i_ind-1]==b[j_ind-1]), 
               max_val );
      }
    }
  }
    
  return 0;
}

CilkPrioCommandDefine(void,recursive_process_sw_tiles,(int *stor, char *a, char *b, int n, int ibase, int start, int end), {
    int count = end - start;
    int mid;
    cilk_enable_spawn_in_this_func();
    while (count > 1) {
      mid = start + count/2;
      cilk_pspawn_void(f0P,recursive_process_sw_tiles,stor, a, b, n, ibase, start, mid);
      start = mid;
      count = end - start;
    }
    int iB = ibase - start;
    process_sw_tile(stor, a, b, n, iB, start);
    cilk_psync;
  });

CilkPrioCommandDefine(int, wave_sw_with_futures,(int *stor, char *a, char *b, int n), {
    int nBlocks = NUM_BLOCKS(n);
    for(int wave_front = 0; wave_front < nBlocks; wave_front++) {
      cilk_run_command(recursive_process_sw_tiles,stor, a, b, n, wave_front, 0, wave_front+1);
    }
    for(int wave_front = 1; wave_front < nBlocks; wave_front++) {
      int iBase = nBlocks + wave_front - 1;
      cilk_run_command(recursive_process_sw_tiles,stor, a, b, n, iBase, wave_front, nBlocks);
    }
    return stor[n*(n-1) + n-1];
  });



//FIB_FUNCTIONS
CilkPrioCommandDefine(int,fib,(int n), {
    int x;
    int y;
    if(n < 2) {
      return n;
    }
    cilk_enable_spawn_in_this_func();
    cilk_pspawn(f1P,&x,fib,n-1);
    y = cilk_run_command(fib,n - 2);
    cilk_psync;
    return x+y;
  });


//MM_FUNCTIONS
int cilk_rand(void) {
  int result;
  rand_nxt = rand_nxt * 1103515245 + 12345;
  result = (rand_nxt >> 16) % ((unsigned int) RAND_MAX + 1);
  return result;
}

void zero(REAL *M, int n){
  int i;
  for(i = 0; i < n * n; i++) {
    M[i] = 0.0;
  }
}

void init_rm(REAL *M, int n){
  int i;
  for(i = 0; i < n * n; i++) {
    M[i] = (REAL) cilk_rand();
  }
}

unsigned int z_convert(int row, int col){

  unsigned int z; // z gets the resulting 32-bit Morton Number.  
  // x and y must initially be less than 65536.
  // The top and the left boundary 

  col = (col | (col << S[3])) & Q[3];
  col = (col | (col << S[2])) & Q[2];
  col = (col | (col << S[1])) & Q[1];
  col = (col | (col << S[0])) & Q[0];

  row = (row | (row << S[3])) & Q[3];
  row = (row | (row << S[2])) & Q[2];
  row = (row | (row << S[1])) & Q[1];
  row = (row | (row << S[0])) & Q[0];

  z = col | (row << 1);

  return z;
}
int block_convert(int row, int col){
  int block_index = z_convert(row >> POWER, col >> POWER);
  return (block_index * BASE_CASE << POWER) 
    + ((row - ((row >> POWER) << POWER)) << POWER) 
    + (col - ((col >> POWER) << POWER));
}

CilkPrioCommandDefine(void,mat_mul_par, (const REAL *A, const REAL * B, REAL *C, int n),{
    //void mat_mul_par(const REAL *const A, const REAL *const B, REAL *C, int n){
    //BASE CASE: here computation is switched to itterative matrix multiplication
    //At the base case A, B, and C point to row order matrices of n x n
    if(n == BASE_CASE) {
      int i, j, k;
      for(i = 0; i < n; i++){
	for(k = 0; k < n; k++){
	  REAL c = 0.0;
	  for(j = 0; j < n; j++){
	    c += A[i * n + j] * B[j* n + k];
	  }
	  C[i * n + k] += c;
	}
      }
      return;
    });

  //partition each matrix into 4 sub matrices
  //each sub-matrix points to the start of the z pattern
  const REAL *const A1 = &A[block_convert(0,0)];
  const REAL *const A2 = &A[block_convert(0, n >> 1)]; //bit shift to divide by 2
  const REAL *const A3 = &A[block_convert(n >> 1,0)];
  const REAL *const A4 = &A[block_convert(n >> 1, n >> 1)];

  const REAL *const B1 = &B[block_convert(0,0)];
  const REAL *const B2 = &B[block_convert(0, n >> 1)];
  const REAL *const B3 = &B[block_convert(n >> 1, 0)];
  const REAL *const B4 = &B[block_convert(n >> 1, n >> 1)];
    
  REAL *C1 = &C[block_convert(0,0)];
  REAL *C2 = &C[block_convert(0, n >> 1)];
  REAL *C3 = &C[block_convert(n >> 1,0)];
  REAL *C4 = &C[block_convert(n >> 1, n >> 1)];
  cilk_enable_spawn_in_this_func();
  //recrusively call the sub-matrices for evaluation in parallel
  cilk_pspawn_void(f2P, mat_mul_par,A1, B1, C1, n >> 1);
  cilk_pspawn_void(f2P, mat_mul_par,A1, B2, C2, n >> 1);
  cilk_pspawn_void(f2P, mat_mul_par,A3, B1, C3, n >> 1);
  cilk_run_command(mat_mul_par,A3, B2, C4, n >> 1);
  cilk_psync; //wait here for first round to finish

  cilk_pspawn_void(f2P, mat_mul_par,A2, B3, C1, n >> 1);
  cilk_pspawn_void(f2P, mat_mul_par,A2, B4, C2, n >> 1);
  cilk_pspawn_void(f2P, mat_mul_par,A4, B3, C3, n >> 1);
  cilk_run_command(mat_mul_par,A4, B4, C4, n >> 1);
  cilk_psync; //wait here for all second round to finish
  }

//SORT_FUNCTIONS
  static inline ELM med3(ELM a, ELM b, ELM c) {

  if (a < b) {
    if (b < c) {
      return b;
    } else {
      if (a < c)
        return c;
      else
        return a;
    }
  } else {
    if (b > c) {
      return b;
    } else {
      if (a > c)
        return c;
      else
        return a;
    }
  }
}

static inline ELM choose_pivot(ELM *low, ELM *high) {

  return med3(*low, *high, low[(high - low) / 2]);
}
ELM *binsplit(ELM val, ELM *low, ELM *high) {

  /*
   * returns index which contains greatest element <= val.  If val is
   * less than all elements, returns low-1
   */
  ELM *mid;

  while (low != high) {
    mid = low + ((high - low + 1) >> 1);
    if (val <= *mid)
      high = mid - 1;
    else
      low = mid;
  }

  if (*low > val)
    return low - 1;
  else
    return low;
}

static ELM *seqpart(ELM *low, ELM *high) {

  ELM pivot;
  ELM h, l;
  ELM *curr_low = low;
  ELM *curr_high = high;

  pivot = choose_pivot(low, high);

  while (1) {
    while ((h = *curr_high) > pivot)
      curr_high--;

    while ((l = *curr_low) < pivot)
      curr_low++;

    if (curr_low >= curr_high)
      break;

    *curr_high-- = l;
    *curr_low++ = h;
  }

  /*
   * I don't know if this is really necessary.
   * The problem is that the pivot is not always the
   * first element, and the partition may be trivial.
   * However, if the partition is trivial, then
   * *high is the largest element, whence the following
   * code.
   */
  if (curr_high < high)
    return curr_high;
  else
    return curr_high - 1;
}

static void insertion_sort(ELM *low, ELM *high) {

  ELM *p, *q;
  ELM a, b;

  for (q = low + 1; q <= high; ++q) {
    a = q[0];
    for (p = q - 1; p >= low && (b = p[0]) > a; p--)
      p[1] = b;
    p[1] = a;
  }
}

void seqquick(ELM *low, ELM *high) {

  ELM *p;

  while (high - low >= INSERTIONSIZE) {
    p = seqpart(low, high);
    seqquick(low, p);
    low = p + 1;
  }

  insertion_sort(low, high);
}

void seqmerge(ELM *low1, ELM *high1, 
	      ELM *low2, ELM *high2, ELM *lowdest) {

  ELM a1, a2;

  /*
   * The following 'if' statement is not necessary
   * for the correctness of the algorithm, and is
   * in fact subsumed by the rest of the function.
   * However, it is a few percent faster.  Here is why.
   *
   * The merging loop below has something like
   *   if (a1 < a2) {
   *        *dest++ = a1;
   *        ++low1;
   *        if (end of array) break;
   *        a1 = *low1;
   *   }
   *
   * Now, a1 is needed immediately in the next iteration
   * and there is no way to mask the latency of the load.
   * A better approach is to load a1 *before* the end-of-array
   * check; the problem is that we may be speculatively
   * loading an element out of range.  While this is
   * probably not a problem in practice, yet I don't feel
   * comfortable with an incorrect algorithm.  Therefore,
   * I use the 'fast' loop on the array (except for the last 
   * element) and the 'slow' loop for the rest, saving both
   * performance and correctness.
   */

  if (low1 < high1 && low2 < high2) {
    a1 = *low1;
    a2 = *low2;
    for (;;) {
      if (a1 < a2) {
        *lowdest++ = a1;
        a1 = *++low1;
        if (low1 >= high1)
          break;
      } else {
        *lowdest++ = a2;
        a2 = *++low2;
        if (low2 >= high2)
          break;
      }
    }
  }
  if (low1 <= high1 && low2 <= high2) {
    a1 = *low1;
    a2 = *low2;
    for (;;) {
      if (a1 < a2) {
        *lowdest++ = a1;
        ++low1;
        if (low1 > high1)
          break;
        a1 = *low1;
      } else {
        *lowdest++ = a2;
        ++low2;
        if (low2 > high2)
          break;
        a2 = *low2;
      }
    }
  }
  if (low1 > high1) {
    memcpy(lowdest, low2, sizeof(ELM) * (high2 - low2 + 1));
  } else {
    memcpy(lowdest, low1, sizeof(ELM) * (high1 - low1 + 1));
  }
}
CilkPrioCommandDefine(void,cilkmerge,(ELM *low1, ELM *high1, ELM *low2, ELM *high2, ELM *lowdest), {
    //void cilkmerge(ELM *low1, ELM *high1, ELM *low2, ELM *high2, ELM *lowdest) {

    /*
     * Cilkmerge: Merges range [low1, high1] with range [low2, high2] 
     * into the range [lowdest, ...]  
     */

    /*
     * We want to take the middle element (indexed by split1) from the
     * larger of the two arrays.  The following code assumes that split1
     * is taken from range [low1, high1].  So if [low1, high1] is
     * actually the smaller range, we should swap it with [low2, high2] 
     */

    ELM *split1, *split2;	/*
				 * where each of the ranges are broken for 
				 * recursive merge 
				 */
    long int lowsize;		/*
                                 * total size of lower halves of two
                                 * ranges - 2 
                                 */

    if (high2 - low2 > high1 - low1) {
      swap_indices(low1, low2);
      swap_indices(high1, high2);
    }

    if (high1 < low1) {
      /* smaller range is empty */
      memcpy(lowdest, low2, sizeof(ELM) * (high2 - low2));
      return;
    }

    if (high2 - low2 < MERGESIZE) {
      seqmerge(low1, high1, low2, high2, lowdest);
      return;
    }
    /*
     * Basic approach: Find the middle element of one range (indexed by
     * split1). Find where this element would fit in the other range
     * (indexed by split 2). Then merge the two lower halves and the two
     * upper halves. 
     */

    split1 = ((high1 - low1 + 1) / 2) + low1;
    split2 = binsplit(*split1, low2, high2);
    lowsize = split1 - low1 + split2 - low2;

    /* 
     * directly put the splitting element into
     * the appropriate location
     */
    *(lowdest + lowsize + 1) = *split1;
    cilk_enable_spawn_in_this_func();
    cilk_pspawn_void(f3P, cilkmerge,low1, split1 - 1, low2, split2, lowdest);
    cilk_run_command(cilkmerge,split1 + 1, high1, split2 + 1, high2, lowdest + lowsize + 2);
    cilk_psync;

    return;
  });
CilkPrioCommandDefine(void,cilksort,(ELM *low, ELM *tmp, long size), {
    //void cilksort(ELM *low, ELM *tmp, long size) {

    /*
     * divide the input in four parts of the same size (A, B, C, D)
     * Then:
     *   1) recursively sort A, B, C, and D (in parallel)
     *   2) merge A and B into tmp1, and C and D into tmp2 (in parallel)
     *   3) merbe tmp1 and tmp2 into the original array
     */

    long quarter = size / 4;
    ELM *A, *B, *C, *D, *tmpA, *tmpB, *tmpC, *tmpD;

    if (size < QUICKSIZE) {
      /* quicksort when less than 1024 elements */
      seqquick(low, low + size - 1);
      return;
    }

    A = low;
    tmpA = tmp;
    B = A + quarter;
    tmpB = tmpA + quarter;
    C = B + quarter;
    tmpC = tmpB + quarter;
    D = C + quarter;
    tmpD = tmpC + quarter;
    cilk_enable_spawn_in_this_func();
    cilk_pspawn_void(f3P, cilksort,A, tmpA, quarter);
    cilk_pspawn_void(f3P, cilksort,B, tmpB, quarter);
    cilk_pspawn_void(f3P, cilksort,C, tmpC, quarter);
    cilk_run_command(cilksort,D, tmpD, size - 3 * quarter);
    cilk_psync;

    cilk_pspawn_void(f3P, cilkmerge,A, A + quarter - 1, B, B + quarter - 1, tmpA);
    cilk_run_command(cilkmerge,C, C + quarter - 1, D, low + size - 1, tmpC);
    cilk_psync;

    cilk_run_command(cilkmerge,tmpA, tmpC - 1, tmpC, tmpA + size - 1, A);
		   
    return;
  });


//fun0 -> wrapper for sw
CilkPrioCommandDefine(int,fun0,(int index, struct timespec* starts, struct timespec * ends, cilk::pfuture<int, f0P>* f,
				int* stor1, char* a1, char* b1, int n),{
			cilk_run_command(wave_sw_with_futures,stor1, a1, b1, n);
			clock_gettime(CLOCK_MONOTONIC, &ends[index]);
			free(stor1);
			if(f){
			  cilk_pfuture_get(f);
			}
			return 0;
		      });

//fun1 -> wrapper for fib
CilkPrioCommandDefine(int,fun1,(int index, struct timespec* starts, struct timespec * ends, cilk::pfuture<int, f1P>* f,
				int n),{
			cilk_run_command(fib,n);
			clock_gettime(CLOCK_MONOTONIC, &ends[index]);
			if(f){
			  cilk_pfuture_get(f);
			}
			return 0;
		      });

//fun2 -> wrapper for mm
CilkPrioCommandDefine(int,fun2,(int index, struct timespec* starts, struct timespec * ends, cilk::pfuture<int, f2P>* f,
				REAL* A,REAL* B,REAL* C,int n),{

			cilk_run_command(mat_mul_par,A,B,C,n);
			clock_gettime(CLOCK_MONOTONIC, &ends[index]);
			free(C);
			if(f){
			  cilk_pfuture_get(f);
			}
			return 0;
		      });

//fun3 -> wrapper for sort
CilkPrioCommandDefine(int,fun3,(int index, struct timespec* starts, struct timespec * ends, cilk::pfuture<int, f3P>* f,
				ELM* array, ELM* tmp, long size),{

			cilk_run_command(cilksort,array, tmp, size);
			clock_gettime(CLOCK_MONOTONIC, &ends[index]);
			free(array);
			free(tmp);
			if(f){
			  cilk_pfuture_get(f);
			}
			return 0;
		      });


//gets wait till next time (poisson process)
//rateParameter: wait time
double nextTime(double rateParameter){
  return (double)(-logf(1.0f-((float)random()/den))/rateParameter);
}

//runs a given job wrapper (based on fNum)
//fNum: which function to run
//starts: start time for job
//ends: //end time for job
CilkPrioCommandDefine(int,runner,(int fNum, struct timespec * starts, struct timespec* ends),{
    if(verbose){
      printf("Running Job Scheduler: %d\n", fNum);
    }
    if(fNum==0){
      //SETUP SW
      int n=SW_N;
      int bSize=SW_BSIZE;
      base_case_log = ilog2(bSize);
      char *a1 = (char *)malloc(n * sizeof(char));
      char *b1 = (char *)malloc(n * sizeof(char));
      /* Generate random inputs; a/b[n-1] not used */
      gen_rand_string(a1, n-1, SIZE_OF_ALPHABETS);
      gen_rand_string(b1, n-1, SIZE_OF_ALPHABETS);
      a1[n-1] = '\0';
      b1[n-1] = '\0';
     
      pthread_barrier_wait(&sBarrier);
      if(duration){
	struct timespec curT, startT;
	int timerfd = timerfd_create(CLOCK_MONOTONIC,0);
	int old_flags=fcntl(timerfd, F_GETFL,0);
	if(fcntl(timerfd, F_SETFL, old_flags|O_NONBLOCK)<0){
	  fprintf(stderr,"Error setting timer fd\n");
	  fprintf(stderr,"%s\n", strerror(errno));
	  return 0;
	}
      
	struct itimerspec timspec;
      	bzero(&timspec, sizeof(timspec));
	timspec.it_interval.tv_sec = 0;
	timspec.it_interval.tv_nsec = 0;
	long nt=(long)(ns*nextTime((float)fWait[fNum]));
	long sec = nt/ns;
	nt=nt-(ns2*sec);
	if((!sec)&&(!nt)){
	  nt=1;
	}
	timspec.it_value.tv_sec = sec;
	timspec.it_value.tv_nsec = nt;
	int res = timerfd_settime(timerfd, 0, &timspec, 0);
	if(res < 0){
	  perror("timerfd_settime:");
	}
	uint64_t expirations = 0;
	int i =0;
	clock_gettime(CLOCK_MONOTONIC, &startT);
	while( (res = cilk_read_sync(timerfd, (char*)&expirations, sizeof(expirations)))){
	  if(res < 0){ perror("read:"); 
	    clock_gettime(CLOCK_MONOTONIC, &curT);
	    if(difftimespecs(curT, startT)>=duration){
	      return 0;
	    }
	    continue; }
	  clock_gettime(CLOCK_MONOTONIC, &curT);
	  if(difftimespecs(curT, startT)>=duration){
	    return 0;
	  }
	  nt=(long)(ns*nextTime((float)fWait[fNum]));
	  sec = nt/ns;
	  nt=nt-(ns2*sec);
	  if((!sec)&&(!nt)){
	    nt=1;
	  }
	  timspec.it_value.tv_sec = sec;
	  timspec.it_value.tv_nsec = nt;

	  res = timerfd_settime(timerfd, 0, &timspec, 0);
	  if(res < 0){
	    perror("timerfd_settime:");
	  }
	  int * stor1 = (int *) malloc(sizeof(int) * n * n);
	  clock_gettime(CLOCK_MONOTONIC, &starts[i]);
	  cilk::pfuture<int, f0P>* temp = new cilk::pfuture<int, f0P>();
	  cilk_pfuture_create(temp, fun0,i, starts, ends,f_futs0,
			      stor1, a1, b1,n);
	  f_futs0=temp;
	  i++;
	}
      }

    }
    else if(fNum==1){
      int n = FIB_N;
      pthread_barrier_wait(&sBarrier);
      if(duration){
	struct timespec curT, startT;

	int timerfd = timerfd_create(CLOCK_MONOTONIC,0);
	int old_flags=fcntl(timerfd, F_GETFL,0);
	if(fcntl(timerfd, F_SETFL, old_flags|O_NONBLOCK)<0){
	  fprintf(stderr,"Error setting timer fd\n");
	  fprintf(stderr,"%s\n", strerror(errno));
	  return 0;
	}
      
	struct itimerspec timspec;
      
      	bzero(&timspec, sizeof(timspec));
	timspec.it_interval.tv_sec = 0;
	timspec.it_interval.tv_nsec = 0;

	long nt=(long)(ns*nextTime((float)fWait[fNum]));
	long sec = nt/ns;
	nt=nt-(ns2*sec);
	if((!sec)&&(!nt)){
	  nt=1;
	}
	timspec.it_value.tv_sec = sec;
	timspec.it_value.tv_nsec = nt;

	
	int res = timerfd_settime(timerfd, 0, &timspec, 0);
	if(res < 0){
	  perror("timerfd_settime:");
	}
	uint64_t expirations = 0;
	int i =0;
	clock_gettime(CLOCK_MONOTONIC, &startT);
	while( (res = cilk_read_sync(timerfd, (char*)&expirations, sizeof(expirations)))){
	  if(res < 0){ perror("read:"); 
	    clock_gettime(CLOCK_MONOTONIC, &curT);
	    if(difftimespecs(curT, startT)>=duration){
	      return 0;
	    }
	    continue; }
	  clock_gettime(CLOCK_MONOTONIC, &curT);
	  if(difftimespecs(curT, startT)>=duration){
	    return 0;
	  }
	  nt=(long)(ns*nextTime((float)fWait[fNum]));
	  sec = nt/ns;
	  nt=nt-(ns2*sec);
	  if((!sec)&&(!nt)){
	    nt=1;
	  }
	  timspec.it_value.tv_sec = sec;
	  timspec.it_value.tv_nsec = nt;
	  res = timerfd_settime(timerfd, 0, &timspec, 0);
	  if(res < 0){
	    perror("timerfd_settime:");
	  }
	  clock_gettime(CLOCK_MONOTONIC, &starts[i]);
	  cilk::pfuture<int,f1P>* temp = new cilk::pfuture<int,f1P>();
	  cilk_pfuture_create(temp, fun1,i, starts, ends, f_futs1,
			      n);

	  f_futs1=temp;
	  i++;
	}
      }

    }
    else if(fNum==2){
      int n=MM_N;
      POWER=MM_POWER;
      BASE_CASE=1<<POWER;
      REAL *A, *B;

      A = (REAL *) malloc(n * n * sizeof(REAL)); //source matrix 
      B = (REAL *) malloc(n * n * sizeof(REAL)); //source matrix

      init_rm(A, n);
      init_rm(B, n);

      pthread_barrier_wait(&sBarrier);
      if(duration){
	struct timespec curT, startT;

	int timerfd = timerfd_create(CLOCK_MONOTONIC,0);
	int old_flags=fcntl(timerfd, F_GETFL,0);
	if(fcntl(timerfd, F_SETFL, old_flags|O_NONBLOCK)<0){
	  fprintf(stderr,"Error setting timer fd\n");
	  fprintf(stderr,"%s\n", strerror(errno));
	  return 0;
	}
      
	struct itimerspec timspec;
      
      	bzero(&timspec, sizeof(timspec));
	timspec.it_interval.tv_sec = 0;
	timspec.it_interval.tv_nsec = 0;
	long nt=(long)(ns*nextTime((float)fWait[fNum]));
	long sec = nt/ns;
	nt=nt-(ns2*sec);
	if((!sec)&&(!nt)){
	  nt=1;
	}
	timspec.it_value.tv_sec = sec;
	timspec.it_value.tv_nsec = nt;
	int res = timerfd_settime(timerfd, 0, &timspec, 0);
	if(res < 0){
	  perror("timerfd_settime:");
	}
	uint64_t expirations = 0;
	int i =0;
	clock_gettime(CLOCK_MONOTONIC, &startT);
	while( (res = cilk_read_sync(timerfd, (char*)&expirations, sizeof(expirations)))){
	  if(res < 0){ perror("read:"); 
	    clock_gettime(CLOCK_MONOTONIC, &curT);
	    if(difftimespecs(curT, startT)>=duration){
	      return 0;
	    }
	    continue; }
	  clock_gettime(CLOCK_MONOTONIC, &curT);
	  if(difftimespecs(curT, startT)>=duration){
	    return 0;
	  }
	  nt=(long)(ns*nextTime((float)fWait[fNum]));
	  sec = nt/ns;
	  nt=nt-(ns2*sec);
	  if((!sec)&&(!nt)){
	    nt=1;
	  }
	  timspec.it_value.tv_sec = sec;
	  timspec.it_value.tv_nsec = nt;
	  res = timerfd_settime(timerfd, 0, &timspec, 0);
	  if(res < 0){
	    perror("timerfd_settime:");
	  }
	  REAL* C = (REAL *) malloc(n * n * sizeof(REAL)); //result matrix
	  zero(C, n);
	  clock_gettime(CLOCK_MONOTONIC, &starts[i]);
	  cilk::pfuture<int,f2P>* temp = new cilk::pfuture<int,f2P>();
	  cilk_pfuture_create(temp, fun2,i, starts, ends,f_futs2,
			      A,B,C,n);
	  f_futs2=temp;
	  i++;

	}
      }
    }
    else{

      pthread_barrier_wait(&sBarrier);
      if(duration){
	struct timespec curT, startT;

	int timerfd = timerfd_create(CLOCK_MONOTONIC,0);
	int old_flags=fcntl(timerfd, F_GETFL,0);
	if(fcntl(timerfd, F_SETFL, old_flags|O_NONBLOCK)<0){
	  fprintf(stderr,"Error setting timer fd\n");
	  fprintf(stderr,"%s\n", strerror(errno));
	  return 0;
	}
      
	struct itimerspec timspec;
      
      	bzero(&timspec, sizeof(timspec));
	timspec.it_interval.tv_sec = 0;
	timspec.it_interval.tv_nsec = 0;
	long nt=(long)(ns*nextTime((float)fWait[fNum]));
	long sec = nt/ns;

	nt=nt-(ns2*sec);
	if((!sec)&&(!nt)){
	  nt=1;
	}
	timspec.it_value.tv_sec = sec;
	timspec.it_value.tv_nsec = nt;

	
	int res = timerfd_settime(timerfd, 0, &timspec, 0);
	if(res < 0){
	  perror("timerfd_settime:");
	}
	uint64_t expirations = 0;
	int i =0;
	clock_gettime(CLOCK_MONOTONIC, &startT);
	while( (res = cilk_read_sync(timerfd, (char*)&expirations, sizeof(expirations)))){
	  if(res < 0){ perror("read:"); 
	    clock_gettime(CLOCK_MONOTONIC, &curT);
	    if(difftimespecs(curT, startT)>=duration){
	      return 0;
	    }
	    continue; }
	  clock_gettime(CLOCK_MONOTONIC, &curT);
	  if(difftimespecs(curT, startT)>=duration){
	    return 0;
	  }
	  nt=(long)(ns*nextTime((float)fWait[fNum]));
	  sec = nt/ns;
	  nt=nt-(ns2*sec);
	  if((!sec)&&(!nt)){
	    nt=1;
	  }
	  timspec.it_value.tv_sec = sec;
	  timspec.it_value.tv_nsec = nt;

	  res = timerfd_settime(timerfd, 0, &timspec, 0);
	  if(res < 0){
	    perror("timerfd_settime:");
	  }
	  long size=SORT_N;
	  ELM* array = (ELM *) malloc(size * sizeof(ELM));
	  ELM* tmp = (ELM *) malloc(size * sizeof(ELM));
      
	  fill_array(array, size);
	  clock_gettime(CLOCK_MONOTONIC, &starts[i]);
	  cilk::pfuture<int,f3P>* temp = new cilk::pfuture<int, f3P>();
	  cilk_pfuture_create(temp, fun3,i, starts, ends,f_futs3,
			      array, tmp, size);

	  f_futs3=temp;
	  i++;
	}
      }

    }
    return 0;
  });

int main(int argc, char** argv){
  cilk_quantum_length_us = cilk_get_quantum_length_us();
  cilk_rho = cilk_get_rho();
  cilk_util_bound = cilk_get_util_bound();
  cilk_init_desire = cilk_get_initial_desire();
  cilk_rr_worker_count = cilk_get_round_robin_worker_count();
  cilk_reserved_w_per_lvl = cilk_get_reserved_workers_per_level();

  progname = argv[0];
  ArgParser* ap = createArgumentParser(&argp);
  int ok = parseArguments(ap, argc, argv);
  if (ok) {
    fprintf(stderr,"Error parsing arguments");
    return -1;
  }
  
  cilk_set_quantum_length_us(cilk_quantum_length_us);
  cilk_set_rho(cilk_rho);
  cilk_set_util_bound(cilk_util_bound);
  cilk_set_initial_desire(cilk_init_desire);
  cilk_set_round_robin_worker_count(cilk_rr_worker_count);
  cilk_set_reserved_workers_per_level(cilk_reserved_w_per_lvl);
  if(verbose){
    printf("rho:ee %lf, ql: %d, ut: %lf\n",cilk_rho, cilk_quantum_length_us, cilk_util_bound);
  }
  for(int i =0;i<argc;i++){
    printf("%s ", argv[i]);
  }
  printf("\n");
  fflush(stdout);
  
  if(1!=((!!requests)+(!!duration))){
    fprintf(stderr,"Didnt specify time or calls\n");
    return -1;
  }
  if(duration){
    for(int i =0;i<numFuns;i++){
      requests=max(requests,duration*((int)(1+fWait[i])));
    }
    requests=requests+(requests<<1);
  }
  duration=duration*us;
  double fSum=0;
  for(int i =0;i<numFuns;i++){
    fSum+=fWait[i];
  }
  if(!fSum){
    fprintf(stderr,"Nothing to run\n");
    return -1;
  }
  int bFuns=0;
  for(int i =0;i<numFuns;i++){
    if(fWait[i]){
      bFuns++;
    }
  }
  my_srand(1);
  if(rseed){
    srand(rseed);
  }
  else{
    srand(time(NULL));
  }
  if(pthread_barrier_init(&sBarrier, NULL, bFuns)){
    fprintf(stderr,"Error initializing barrier\n");
    return -1;
  }
  struct timespec ** starts=(struct timespec**)calloc(numFuns, sizeof(struct timespec*));
  struct timespec ** ends=(struct timespec**)calloc(numFuns, sizeof(struct timespec*));
  for(int i =0;i<numFuns;i++){
    starts[i]=(struct timespec*)calloc(requests, sizeof(struct timespec));
    ends[i]=(struct timespec*)calloc(requests, sizeof(struct timespec));
  }


  

  cilk::pfuture<int, RunP>* t[numFuns];
  for(int i =0;i<numFuns;i++){
    t[i]= new cilk::pfuture<int, RunP>();
  }
  for(int i =0;i<numFuns;i++){
    if(fWait[i]){
      if(verbose){
	printf("do: %d\n", i);
      }
      cilk_pfuture_create(t[i], runner,i, starts[i], ends[i]);
    }
  }
  for(int i =0;i<numFuns;i++){
    if(fWait[i]){
      if(verbose){
	printf("Waiting on %d\n", i);
      }
      cilk_pfuture_get(t[i]);
      if(verbose){
	printf("got %d\n", i);
      }
    }
  }


  printf("Event, Avg(us), Max(us), Min(us), Stdev(us), Stdev(%%), 50%%(us), 90%%(us), 95%%(us), 99%%(us)\n");
  char buf[256] = "";
  for(int iter=0;iter<numFuns;iter++){
    int i = order[iter];
    unsigned long* h0=(unsigned long*)ends[i], *h1=(unsigned long*)starts[i];
    int tIndex=0;
    unsigned long* data = (unsigned long*)calloc(requests, sizeof(unsigned long));
    while(h0[(tIndex<<1)]&&
	  h0[(tIndex<<1)+1]&&
	  h1[(tIndex<<1)]&&
	  h1[(tIndex<<1)+1]&&
	  tIndex<requests){
      data[tIndex] = difftimespecs_ns(ends[i][tIndex],starts[i][tIndex]);
      tIndex++;
    }
    sprintf(buf, "%s Timing (avg of %d) Duration %lf sec",
	    fun_name[i],
	    tIndex,
	    (difftimespecs(ends[i][tIndex-1], starts[i][0]))/(1000000.0));
    //    printf("--%s--\n", buf);
    //    print_runtime_summary(data, tIndex);
    print_csv(data, tIndex, (const char *)buf);

    
  }
  fflush(stdout);
  return 0;
}
