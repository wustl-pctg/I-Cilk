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

COMMON_CXXFLAGS = -DTIMES_TO_RUN=10 -DTIMING_COUNT=10 -O3 -flto -g -fcilkplus -fno-omit-frame-pointer -I../src -I../Tapir/src/build/include -std=c++17 -Wall
COMMON_LDFLAGS  = ktiming.o -ltcmalloc -lrt -ldl -lpthread -lnuma -lpthread -lm -lrt

INTERACTIVE_CXXFLAGS = $(COMMON_CXXFLAGS) -I../interactive-cilk/runtime/config/x86 -I../interactive-cilk/runtime/sslib -I../interactive-cilk/include
INTERACTIVE_LDFLAGS 	= $(ICILK_A) $(COMMON_LDFLAGS) 

VANILLA_CXXFLAGS = $(COMMON_CXXFLAGS) -I../cilk-l/runtime/config/x86 -I../cilk-l/runtime/sslib -I../cilk-l/include
VANILLA_LDFLAGS  = $(CILKL_A) $(COMMON_LDFLAGS) 

.PHONY: default all clean
default: all

getoptions.o: getoptions.cpp
	$(CXX) $(INTERACTIVE_CXXFLAGS) -c getoptions.cpp -o getoptions.o

ktiming.o: ktiming.c
	$(CXX) $(INTERACTIVE_CXXFLAGS) -c ktiming.c -o ktiming.o

fib.o: fib.c
	$(CXX) $(INTERACTIVE_CXXFLAGS) -c fib.c -o fib.o

fib-producer.o: fib-producer.c
	$(CXX) $(INTERACTIVE_CXXFLAGS) -c fib-producer.c -o fib-producer.o

fib-options.o: fib-options.c
	$(CXX) $(INTERACTIVE_CXXFLAGS) -c fib-options.c -o fib-options.o

TARGETS = fib-srv-se
APPS = fib-srv-se

fib-srv-se: fib-srv-se.c fib.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(COMMON_CXXFLAGS) -c fib-srv-se.c -o fib-srv-se.o
	$(CXX) -flto fib-srv-se.o fib.o fib-producer.o getoptions.o fib-options.o -o fib-srv-se $(COMMON_LDFLAGS)

TARGETS = fib-srv-l
APPS = fib-srv-l

fib-srv-l: $(ICILK_A) fib-srv-l.c fib.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(INTERACTIVE_CXXFLAGS) -c fib-srv-l.c -o fib-srv-l.o
	$(CXX) -flto fib-srv-l.o fib.o fib-producer.o getoptions.o fib-options.o -o fib-srv-l $(INTERACTIVE_LDFLAGS)

TARGETS += fib-srv-fj
APPS += fib-srv-fj

fib-srv-fj: $(ICILK_A) fib-srv-fj.c fib.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(INTERACTIVE_CXXFLAGS) -c fib-srv-fj.c -o fib-srv-fj.o
	$(CXX) -flto fib-srv-fj.o fib.o fib-producer.o getoptions.o fib-options.o -o fib-srv-fj $(INTERACTIVE_LDFLAGS)

TARGETS += fib-sio-se
APPS += fib-sio-se

fib-sio-se: fib-sio-se.c fib.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(COMMON_CXXFLAGS) -c fib-sio-se.c -o fib-sio-se.o
	$(CXX) -flto fib-sio-se.o fib.o fib-producer.o getoptions.o fib-options.o -o fib-sio-se $(COMMON_LDFLAGS)

TARGETS += fib-sio-l
APPS += fib-sio-l

fib-sio-l: $(ICILK_A) fib-sio-l.c fib.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(INTERACTIVE_CXXFLAGS) -c fib-sio-l.c -o fib-sio-l.o
	$(CXX) -flto fib-sio-l.o fib.o fib-producer.o getoptions.o fib-options.o -o fib-sio-l $(INTERACTIVE_LDFLAGS)

TARGETS += fib-sio-fj
APPS += fib-sio-fj

fib-sio-fj: $(ICILK_A) fib-sio-fj.c fib.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(INTERACTIVE_CXXFLAGS) -c fib-sio-fj.c -o fib-sio-fj.o
	$(CXX) -flto fib-sio-fj.o fib.o fib-producer.o getoptions.o fib-options.o -o fib-sio-fj $(INTERACTIVE_LDFLAGS)

TARGETS += fib-mr-se
APPS += fib-mr-se

fib-mr-se: fib-mr-se.c fib.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(COMMON_CXXFLAGS) -c fib-mr-se.c -o fib-mr-se.o
	$(CXX) -flto fib-mr-se.o fib.o fib-producer.o getoptions.o fib-options.o -o fib-mr-se $(COMMON_LDFLAGS)

TARGETS += fib-mr-l
APPS += fib-mr-l

fib-mr-l: $(ICILK_A) fib-mr-l.c fib.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(INTERACTIVE_CXXFLAGS) -c fib-mr-l.c -o fib-mr-l.o
	$(CXX) -flto fib-mr-l.o fib.o fib-producer.o getoptions.o fib-options.o -o fib-mr-l $(INTERACTIVE_LDFLAGS)

TARGETS += fib-mr-fj
APPS += fib-mr-fj

fib-mr-fj: $(ICILK_A) fib-mr-fj.c fib.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(INTERACTIVE_CXXFLAGS) -c fib-mr-fj.c -o fib-mr-fj.o
	$(CXX) -flto fib-mr-fj.o fib.o fib-producer.o getoptions.o fib-options.o -o fib-mr-fj $(INTERACTIVE_LDFLAGS)

TARGETS += fib-bench-se
APPS += fib-bench-se

fib-bench-se: $(ICILK_A) fib-bench-se.c fib.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(COMMON_CXXFLAGS) -c fib-bench-se.c -o fib-bench-se.o
	$(CXX) -flto fib-bench-se.o fib.o fib-options.o getoptions.o -o fib-bench-se $(COMMON_LDFLAGS)

TARGETS += fib-bench
APPS += fib-bench

fib-bench: fib-bench.cpp fib.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(INTERACTIVE_CXXFLAGS) -c fib-bench.cpp -o fib-bench.o
	$(CXX) -flto fib-bench.o fib.o fib-options.o getoptions.o -o fib-bench $(INTERACTIVE_LDFLAGS)

TARGETS += other-test
APPS += other-test

other-test: other-test.cpp getoptions.o ktiming.o
	$(CXX) $(INTERACTIVE_CXXFLAGS) -c other-test.cpp -o other-test.o
	$(CXX) -flto other-test.o getoptions.o -o fib-bench $(INTERACTIVE_LDFLAGS)

TARGETS += proxySelf
APPS += proxySelf

proxySelf: $(ICILK_A) ../proxy/proxySelf.c
	$(CXX) $(INTERACTIVE_CXXFLAGS) -c ../proxy/proxySelf.c -o proxySelf.o
	$(CXX) -flto proxySelf.o  -o proxySelf $(INTERACTIVE_LDFLAGS)

TARGETS += con
APPS += con

con: $(ICILK_A) ../drivercode/driver/con.c
	$(CXX) $(INTERACTIVE_CXXFLAGS) -c ../drivercode/driver/con.c -o con.o
	$(CXX) -flto con.o  -o con $(INTERACTIVE_LDFLAGS)

TARGETS += client
APPS += client

client: $(ICILK_A) ../proxy/client.c
	$(CXX) $(INTERACTIVE_CXXFLAGS) -c ../proxy/client.c -o client.o
	$(CXX) -flto client.o -o client $(INTERACTIVE_LDFLAGS)


###########################################################################
# Though shalt not cross this line lest thou knowest what thou art doing! #
###########################################################################

all: $(TARGETS)

clean:
	rm -f *.o $(APPS)
