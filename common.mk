BASE_DIR=$(dir $(abspath $(lastword $(MAKEFILE_LIST))))
include $(BASE_DIR)/config.mk

CC=$(COMPILER_HOME)/bin/clang
CXX=$(COMPILER_HOME)/bin/clang++

ARFLAGS = rcs
OPT = -O3 #-march=native -DNDEBUG

ICILK_A = $(BASE_DIR)/interactive-cilk/.libs/libcilkrts.a
CILKL_A = $(BASE_DIR)/cilk-l/.libs/libcilkrts.a

CFLAGS = -g -Wfatal-errors $(INC)
CILKFLAGS = -fcilkplus #-fcilk-no-inline
