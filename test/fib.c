//#include <cilk/cilk.h>
//#include <cilk/future.h>
#include <cilk/cilk_priority.h>
#include <assert.h>

#include <string.h>

#include <fcntl.h>
#include <unistd.h>

#include "fib-producer.h"

#include <inttypes.h>

#include <stdio.h>

int serial_base_case = 15;

int serial_fib(int n) {
    if (n < 2) {
      return n;
    }

    int x = serial_fib(n-1);
    int y = serial_fib(n-2);
    return x+y;
}
/*
int fib(int n) {
    printf("Wrong!\n");
    if (n < serial_base_case) {
        return serial_fib(n);
    }

    int x = 0;
    int y = 0;
    
    x = cilk_spawn fib(n-1);
    y = fib(n-2);
    cilk_sync;
    return x+y;
}
*/


/*
int fib_future(int n) {
    //assert(0);
    //__cilkrts_suspend_deque(1);
    if (n < serial_base_case) {
      return serial_fib(n);
    }

    cilk::pfuture<int, cilk::Low> x;
    cilk::pfuture<int, cilk::Low> y;
    cilk_pfuture_create(&x, fib_future, n-1);
    cilk_pfuture_create(&y, fib_future, n-2);
    return x.get() + y.get();
}
*/
/*
int fib_procrastinatory(int n) {
    if (n < serial_base_case) {
      return serial_fib(n);
    }
    //__cilkrts_stack_frame sf;
    //__cilkrts_enter_frame_fast_1(&sf);

    cilk::future<int> x;
    cilk::future<int> y;
    cilk_procrastinatory_future_create((&x), fib_procrastinatory, n-1);
    cilk_procrastinatory_future_create((&y), fib_procrastinatory, n-2);

    int res = x.get() + y.get();
    //delete x;
    //delete y;
    //__cilkrts_pop_frame(&sf);
    //__cilkrts_leave_frame(&sf);
    return res;
}


int fib_sync_handle(int n) {
    printf("Wrong!\n");
    if (n < serial_base_case) {
      return serial_fib(n);
    }

    cilk_enable_spawn_in_this_func();

    int x = 0;
    int y = 0;
    int x2 = 0;
    int y2 = 0;
    //cilk::future<int> x3;
    //cilk::future<int> y3;

    cilk_spawn2(x, fib_sync_handle, n-1);
    cilk_spawn2(y, fib_sync_handle, n-2);
    cilk_spawn3(x2, fib, n-1); 
    cilk_spawn3(y2, fib, n-2); 
    //cilk_procrastinatory_future_create(&x3, fib_procrastinatory, n-1);
    //cilk_procrastinatory_future_create(&y3, fib_procrastinatory, n-2);
    cilk_sync2();
    assert(x+y == x2+y2);
    //assert(x+y == x3.get() + y3.get());
    return x+y;
}
*/

//int wrap_fib(int n) {
//    int res = fib(n);
//    printf("Res: %d\n", res);
//    return res;
//}
