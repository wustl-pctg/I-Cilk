###########################################################################
# NOTE: Thou shalt add thine build targets to the TARGETS designator, and #
#       thou shalt add thine resulting executables to the APPS designator,#
#       lest thou desire to be charged with polluting the systems of      #
#       thine fellows.                                                    #
###########################################################################

# This MUST be before any includes
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(patsubst %/,%,$(dir $(mkfile_path)))

include ../common.mk

#TCMALLOC_DIR = $(mkfile_dir)/../gperftools-2.7/.libs

#COMMON_CXXFLAGS = -O3 -flto -g -fcilkplus -fno-omit-frame-pointer -fcilk-no-inline -I../src -I../Tapir/src/build/include -std=c++11 -Wall
COMMON_CXXFLAGS = -O3 -flto -g -fno-omit-frame-pointer -I./include/ -std=c++17 -Wall
#COMMON_LDFLAGS  = -L$(TCMALLOC_DIR) -ltcmalloc -lrt -ldl -lpthread -lpthread -lm -lrt
COMMON_LDFLAGS  = -ltcmalloc -lrt -ldl -lpthread -lpthread -lm -lrt

FUTURE_CXXFLAGS = $(COMMON_CXXFLAGS) -I../interactive-cilk/runtime/config/x86 -I../interactive-cilk/runtime/sslib -I../interactive-cilk/include
FUTURE_LDFLAGS 	= $(ICILK_A) $(COMMON_LDFLAGS) 

VANILLA_CXXFLAGS = $(COMMON_CXXFLAGS) -I../cilk-l/runtime/config/x86 -I../cilk-l/runtime/sslib -I../cilk-l/include
VANILLA_LDFLAGS  = $(CILKL_A) $(COMMON_LDFLAGS)


.PHONY: default all clean
default: all

getoptions.o: utils/getoptions.cpp
	$(CXX) $(COMMON_CXXFLAGS) -c utils/getoptions.cpp -o getoptions.o

ktiming.o: utils/ktiming.cpp
	$(CXX) $(COMMON_CXXFLAGS) -c utils/ktiming.cpp -o ktiming.o

arg.o: utils/arg.c utils/arg.h 
	$(CXX) $(COMMON_CXXFLAGS) -c utils/arg.c -o arg.o

timing.o: utils/timing.c utils/timing.h
	$(CXX) $(COMMON_CXXFLAGS) -c utils/timing.c -o timing.o

util.o: utils/util.c utils/util.h
	$(CXX) $(COMMON_CXXFLAGS) -c utils/util.c -o util.o


TARGETS += jsched-noprio
APPS += jsched-noprio

jsched-noprio: $(CILKL_A) jsched/jsched-noprio.c arg.o util.o ktiming.o timing.o utils/stat.h
	$(CXX) $(VANILLA_CXXFLAGS) -c jsched/jsched-noprio.c -o jsched-noprio.o
	$(CXX) -flto jsched-noprio.o arg.o ktiming.o util.o timing.o -o jsched-noprio $(VANILLA_LDFLAGS)

TARGETS += jsched-prio
APPS += jsched-prio

jsched-prio: $(CILKPLUS_A) jsched/jsched-prio.c arg.o util.o ktiming.o timing.o utils/stat.h
	$(CXX) $(FUTURE_CXXFLAGS) -c jsched/jsched-prio.c -o jsched-prio.o
	$(CXX) -flto jsched-prio.o arg.o ktiming.o util.o timing.o -o jsched-prio $(FUTURE_LDFLAGS)


TARGETS += proxy-prio
APPS += proxy-prio

proxy-prio: $(CILKPLUS_A) proxy/proxy-prio.c arg.o util.o timing.o ktiming.o utils/stat.h
	$(CXX) $(FUTURE_CXXFLAGS) -c proxy/proxy-prio.c -o proxy-prio.o
	$(CXX) -flto proxy-prio.o arg.o ktiming.o util.o timing.o -o proxy-prio $(FUTURE_LDFLAGS)

TARGETS += proxy-noprio
APPS += proxy-noprio

proxy-noprio: $(CILKL_A) proxy/proxy-noprio.c arg.o ktiming.o util.o timing.o utils/stat.h
	$(CXX) $(VANILLA_CXXFLAGS) -c proxy/proxy-noprio.c -o proxy-noprio.o
	$(CXX) -flto proxy-noprio.o arg.o ktiming.o util.o timing.o -o proxy-noprio $(VANILLA_LDFLAGS)


TARGETS += con
APPS += ../drivercode/con

con: drivercode/con.c 
	cd drivercode && $(MAKE) con



###########################################################################
# Though shalt not cross this line lest thou knowest what thou art doing! #
###########################################################################

all: $(TARGETS) 

clean:
	rm -f *.o $(APPS)
	(cd drivercode; make clean)
