#ifndef INCLUDED_CILK_MAIN_H
#define INCLUDED_CILK_MAIN_H

#include <cilk/future.h>
#include <cilk/sync_handle.h>
#include <cilk/cilk_io.h>

int cilk_user_main(int argc, char *args[]);

// TODO: We should define main elsewhere
int __attribute__((weak)) main(int argc, char *args[]) {
  CILK_INITIAL_FUNC_PREAMBLE;
  
    int result = cilk_user_main(argc, args);
    //return userProgram.main(argc, args);

  CILK_FUNC_EPILOGUE;

  return result;
}

#define main  cilk_user_main

#endif
