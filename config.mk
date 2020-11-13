BUILD_DIR=/mnt/cilk-plus-futures/build
RUNTIME_HOME=/mnt/cilk-plus-futures/interactive-cilk
COMPILER_HOME=/mnt/cilk-plus-futures/Tapir/src/build
RTS_LIB=$(RUNTIME_HOME)/.libs/libcilkrts.a
LTO=1
ftype ?= structured
