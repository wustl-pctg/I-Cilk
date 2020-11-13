//#include <cilk/cilk.h>
//#include <cilk/cilk_io.h>
#include <cilk/cilk_priority.h>

#include <string.h>

#include <unistd.h>

#include "fib.h"
#include "fib-options.h"
#include "ktiming.h"

#include <inttypes.h>
#include <malloc.h>

int fib_n = 30;
int fib_count = 3000;
int io_delay = 50000;
int nruns = 1;

template <class... Priorities>
constexpr auto formPriorityType() {
  //typedef decltype(formPriorityType<Priorities...>()) otherPrio;
  class intermediate_prio : public Priorities... {
    public:
      //static constexpr int schedulingLevel = std::max({Priority1::schedulingLevel, Priorities::schedulingLevel...}) + 1;
  };

  return intermediate_prio();
}

//template <class Priority1>
//constexpr int calcSchedulingLevel() {
//  return Priority1::schedulingLevel;
//}

template <class Priority1, class... Priorities>
constexpr int calcSchedulingLevel() {
  if constexpr ( sizeof...(Priorities) == 0 ) {
    return Priority1::schedulingLevel;
  } else {
    return std::max(Priority1::schedulingLevel, calcSchedulingLevel<Priorities...>());
  }
}


template <class Priority>
constexpr Priority formPriorityType() {
  return Priority();
}

#define CilkDeclareNewPriority2(NewPrio, NextLowestPrio...)\
  typedef decltype(formPriorityType<NextLowestPrio>()) CILK_PRIO_CAT(NewPrio, INT_PARENT); \
  class NewPrio : public CILK_PRIO_CAT(NewPrio, INT_PARENT) {\
    public:\
           static constexpr int schedulingLevel =\
                                  calcSchedulingLevel<NextLowestPrio>() + 1;\
           /*static int priorityID = -1;*/\
  };\
  __attribute__((constructor (NewPrio::schedulingLevel+100))) __attribute__((weak)) void CILK_PRIO_CAT(NewPrio, UpdatePrioLevel)() {\
    __cilk_highestSchedulingLevel = NewPrio::schedulingLevel;\
    /*if (NewPrio::priorityID == -1) NewPrio::priorityID = cilk::numberOfPriorities++;*/\
  }

CilkDeclareNewPriority(Medium, cilk::Low);
CilkDeclareNewPriority(High, Medium);
CilkDeclareNewPriority(Other, cilk::Low);
CilkDeclareNewPriority(Other2, Medium);
CilkDeclareNewPriority2(Woot, High, Other2, Other);

/* 
 * fib 39: 63245986
 * fib 40: 102334155
 * fib 41: 165580141 
 * fib 42: 267914296
 * fib 43: 433494437
 * fib 44: 701408733
 * fib 45: 1134903170
 */
CilkPrioCommandPrototype(int, fib, int);

/*CilkPrioCommandDefine(int, fib, (int n),
{
  if (n < serial_base_case) {
    return serial_fib(n);
  }

  cilk::pfuture<int, High> x;
  cilk_pfuture_create(&x, fib, n-1);

  // cilk_run_command forces the run to occur
  // at the current priority
  int y_val = cilk_run_command(fib, n-2);
  int x_val = cilk_pfuture_get(&x);

  return x_val + y_val;
}
);
*/
CilkPrioCommandDefine(int, fib, (int n),
{
  if (n < serial_base_case) {
    return serial_fib(n);
  }
  cilk_enable_spawn_in_this_func();

  //cilk::pfuture<int, High> x;
  //cilk_pfuture_create(&x, fib, n-1);
  int x_val = 0, y_val = 0;
  cilk_pspawn(High, &x_val, fib, n-1);

  // cilk_run_command forces the run to occur
  // at the current priority
  if constexpr (cilk::priorityTheSame<cilk_get_curr_priority(), High>::value) {
      y_val = cilk_run_command(fib, n-2);
  } else {
      //cilk_pspawn(Medium, &y_val, fib, n-2);
      cilk::pfuture<int, Medium> fut;
      cilk_pfuture_create(&fut, fib, n-2);
      y_val = cilk_pfuture_get(&fut);
  }
  //int x_val = cilk_pfuture_get(&x);
  //cilk_pspawn(Medium, &y_val, fib, n-1);

  cilk_psync;

  return x_val + y_val;
}
);

int globalRet = 0;

CilkPrioCommandPrototype( void, blah, int);
CilkPrioCommandDefine(void, blah, (int n), {
  globalRet = cilk_run_command(fib, n);
}
);

CilkPrioCommandPrototype( CilkPrioWrapTemplate(cilk::pfuture<void, cilk::Low>*) , runFib, int);

CilkPrioCommandDefine( CilkPrioWrapTemplate( cilk::pfuture<void, cilk::Low>* ), runFib, (int n),
{
  cilk::pfuture<void, cilk::Low>* result = new cilk::pfuture<void, cilk::Low>();

  cilk_pfuture_create(result, blah, n);

  return result;
}
)

int main(int argc, char *args[]) {
    load_fib_options(argc, args);
    int res = 0;

    uint64_t *running_times = (uint64_t*)malloc(nruns*sizeof(uint64_t));
    clockmark_t begin, end;
    cilk_enable_spawn_in_this_func();

    for (int i = 0; i < nruns; i++) {
        begin = ktiming_getmark();

        //cilk::pfuture<int, cilk::Low> comp;
        //cilk_pfuture_create(&comp, fib_future_cmd, fib_n);
        //res = cilk_pfuture_get(&comp);
        
        //cilk_pspawn(cilk::Low, &res, fib, fib_n);
        //cilk_psync;
        cilk::pfuture<void, cilk::Low> *fut = NULL;
        cilk_pspawn(cilk::Low, &fut, runFib, fib_n);
        cilk_psync;

        //res = cilk_pfuture_get(fut);
        cilk_pfuture_get(fut);
        res = globalRet;

        //res = cilk_run_command(fib, fib_n);

        end = ktiming_getmark();
        running_times[i] = ktiming_diff_usec(&begin, &end);
    }

    printf("Res: %d\n", res);

    if(nruns > 10) 
        print_runtime_summary(running_times, nruns); 
    else 
        print_runtime(running_times, nruns); 

    free(running_times);

    return 0;
}
