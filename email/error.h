#pragma once

#include <cassert>
#include <cstdio>

#define checkError(condition, msg, args...)\
  if ((condition)) {\
    auto tmpErrno = errno;\
    fprintf(stderr, msg, ##args);\
    errno = tmpErrno;\
    perror(NULL);\
    assert(!(condition)); /* Assert helps get the line number */ \
    exit(EXIT_FAILURE); /* In case assert is a noop */\
  }
