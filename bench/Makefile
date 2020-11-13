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

VPATH=$(mkfile_dir)/src

.PHONY: default all clean
default: all

getoptions.o: src/common/getoptions.cpp
	$(CXX) $(COMMON_CXXFLAGS) -c src/common/getoptions.cpp -o getoptions.o

ktiming.o: src/common/ktiming.cpp
	$(CXX) $(COMMON_CXXFLAGS) -c src/common/ktiming.cpp -o ktiming.o

fib.o: src/fib/fib.cpp
	$(CXX) $(FUTURE_CXXFLAGS) -c src/fib/fib.cpp -o fib.o

fib-noprio.o: src/fib/fib.cpp
	$(CXX) $(FUTURE_CXXFLAGS) -DDONT_USE_PRIORITY -c src/fib/fib.cpp -o fib-noprio.o

fib-se.o: src/fib/fib.cpp
	$(CXX) $(FUTURE_CXXFLAGS) -DDONT_USE_PRIORITY -c src/fib/fib.cpp -o fib-se.o

fib-producer.o: src/fib/common/fib-producer.cpp
	$(CXX) $(COMMON_CXXFLAGS) -c src/fib/common/fib-producer.cpp -o fib-producer.o

fib-options.o: src/fib/fib-options.cpp
	$(CXX) $(FUTURE_CXXFLAGS) -c src/fib/fib-options.cpp -o fib-options.o

../jsched/utils/arg.o: ../jsched/utils/arg.c ../jsched/utils/arg.h 
	$(CXX) $(COMMON_CXXFLAGS) -c ../jsched/utils/arg.c -o ../jsched/utils/arg.o

../jsched/utils/timing.o: ../jsched/utils/timing.c ../jsched/utils/timing.h
	$(CXX) $(COMMON_CXXFLAGS) -c ../jsched/utils/timing.c -o ../jsched/utils/timing.o

../jsched/utils/util.o: ../jsched/utils/util.c ../jsched/utils/util.h
	$(CXX) $(COMMON_CXXFLAGS) -c ../jsched/utils/util.c -o ../jsched/utils/util.o

TARGETS += bank-prio
APPS += bank-prio

bank-prio: src/bank/bank.cpp getoptions.o ktiming.o
	$(CXX) $(FUTURE_CXXFLAGS) -c src/bank/bank.cpp -o bank.o
	$(CXX) -flto bank.o getoptions.o -o bank-prio $(FUTURE_LDFLAGS)

TARGETS += fib-srv-se
APPS += fib-srv-se

fib-srv-se: src/fib/srv/fib-srv-se.cpp fib-se.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(COMMON_CXXFLAGS) -DDONT_USE_PRIORITY -c src/fib/srv/fib-srv-se.cpp -o fib-srv-se.o
	$(CXX) -flto fib-srv-se.o fib-se.o fib-producer.o getoptions.o ktiming.o fib-options.o -o fib-srv-se $(COMMON_LDFLAGS)

TARGETS += fib-srv-l
APPS += fib-srv-l

fib-srv-l: $(CILKF_A) src/fib/srv/fib-srv-l.cpp fib.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(FUTURE_CXXFLAGS) -DDONT_USE_PRIORITY -c src/fib/srv/fib-srv-l.cpp -o fib-srv-l.o
	$(CXX) -flto fib-srv-l.o fib.o fib-producer.o getoptions.o ktiming.o fib-options.o -o fib-srv-l $(FUTURE_LDFLAGS)

TARGETS += fib-srv-fj
APPS += fib-srv-fj

fib-srv-fj: $(CILKPLUS_A) src/fib/srv/fib-srv-fj.cpp fib.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(FUTURE_CXXFLAGS) -DDONT_USE_PRIORITY -c src/fib/srv/fib-srv-fj.cpp -o fib-srv-fj.o
	$(CXX) -flto fib-srv-fj.o fib.o fib-producer.o getoptions.o ktiming.o fib-options.o -o fib-srv-fj $(FUTURE_LDFLAGS)

TARGETS += fib-sio-se
APPS += fib-sio-se

fib-sio-se: src/fib/sio/fib-sio-se.cpp fib-se.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(COMMON_CXXFLAGS) -DDONT_USE_PRIORITY -c src/fib/sio/fib-sio-se.cpp -o fib-sio-se.o
	$(CXX) -flto fib-sio-se.o fib-se.o fib-producer.o getoptions.o ktiming.o fib-options.o -o fib-sio-se $(COMMON_LDFLAGS)

TARGETS += fib-sio-l
APPS += fib-sio-l

fib-sio-l: $(CILKF_A) src/fib/sio/fib-sio-l.cpp fib.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(FUTURE_CXXFLAGS) -DDONT_USE_PRIORITY -c src/fib/sio/fib-sio-l.cpp -o fib-sio-l.o
	$(CXX) -flto fib-sio-l.o fib.o fib-producer.o getoptions.o ktiming.o fib-options.o -o fib-sio-l $(FUTURE_LDFLAGS)

TARGETS += fib-sio-fj
APPS += fib-sio-fj

fib-sio-fj: $(CILKPLUS_A) src/fib/sio/fib-sio-fj.cpp fib.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(FUTURE_CXXFLAGS) -DDONT_USE_PRIORITY -c src/fib/sio/fib-sio-fj.cpp -o fib-sio-fj.o
	$(CXX) -flto fib-sio-fj.o fib.o fib-producer.o getoptions.o ktiming.o fib-options.o -o fib-sio-fj $(FUTURE_LDFLAGS)

TARGETS += fib-mr-se
APPS += fib-mr-se

fib-mr-se: src/fib/mr/fib-mr-se.cpp fib-se.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(COMMON_CXXFLAGS) -DDONT_USE_PRIORITY -c src/fib/mr/fib-mr-se.cpp -o fib-mr-se.o
	$(CXX) -flto fib-mr-se.o fib-se.o fib-producer.o getoptions.o ktiming.o fib-options.o -o fib-mr-se $(COMMON_LDFLAGS)

TARGETS += fib-mr-l
APPS += fib-mr-l

fib-mr-l: $(CILKF_A) src/fib/mr/fib-mr-l.cpp fib.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(FUTURE_CXXFLAGS) -c src/fib/mr/fib-mr-l.cpp -o fib-mr-l.o
	$(CXX) -flto fib-mr-l.o fib.o fib-producer.o getoptions.o ktiming.o fib-options.o -o fib-mr-l $(FUTURE_LDFLAGS)

TARGETS += fib-mr-fj
APPS += fib-mr-fj

fib-mr-fj: $(CILKPLUS_A) src/fib/mr/fib-mr-fj.cpp fib.o fib-producer.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(FUTURE_CXXFLAGS) -c src/fib/mr/fib-mr-fj.cpp -o fib-mr-fj.o
	$(CXX) -flto fib-mr-fj.o fib.o fib-producer.o getoptions.o ktiming.o fib-options.o -o fib-mr-fj $(FUTURE_LDFLAGS)

TARGETS += fib-bench-se
APPS += fib-bench-se

fib-bench-se: $(CILKPLUS_A) src/fib/fib-bench-se.cpp fib-se.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(COMMON_CXXFLAGS) -DDONT_USE_PRIORITY -c src/fib/fib-bench-se.cpp -o fib-bench-se.o
	$(CXX) -flto fib-bench-se.o fib-se.o fib-options.o getoptions.o ktiming.o -o fib-bench-se $(COMMON_LDFLAGS)

TARGETS += fib-bench-noprio
APPS += fib-bench-noprio

fib-bench-noprio: src/fib/fib-bench.cpp fib-noprio.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(FUTURE_CXXFLAGS) -DDONT_USE_PRIORITY -c src/fib/fib-bench.cpp -o fib-bench-noprio.o
	$(CXX) -flto fib-bench-noprio.o fib-noprio.o fib-options.o getoptions.o ktiming.o -o fib-bench-noprio $(FUTURE_LDFLAGS)

TARGETS += fib-bench-vanilla
APPS += fib-bench-vanilla

fib-bench-vanilla: src/fib/fib-bench.cpp fib-noprio.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(VANILLA_CXXFLAGS) -DDONT_USE_PRIORITY -c src/fib/fib-bench.cpp -o fib-bench-vanilla.o
	$(CXX) -flto fib-bench-vanilla.o fib-noprio.o fib-options.o getoptions.o ktiming.o -o fib-bench-vanilla $(VANILLA_LDFLAGS)

TARGETS += fib-bench-1prio
APPS += fib-bench-1prio

fib-bench-1prio: src/fib/fib-bench.cpp fib.o getoptions.o fib-options.o ktiming.o
	$(CXX) $(FUTURE_CXXFLAGS) -c src/fib/fib-bench.cpp -o fib-bench-1prio.o
	$(CXX) -flto fib-bench-1prio.o fib.o fib-options.o getoptions.o ktiming.o -o fib-bench-1prio $(FUTURE_LDFLAGS)

TARGETS += micro
APPS += micro

micro: src/micro/micro.cpp fib.o ktiming.o getoptions.o fib-options.o
	$(CXX) $(FUTURE_CXXFLAGS) -c src/micro/micro.cpp -o micro.o
	$(CXX) -flto micro.o fib.o ktiming.o getoptions.o fib-options.o -o micro $(FUTURE_LDFLAGS)

TARGETS += old-micro
APPS += old-micro

old-micro: src/micro/old_micro.cpp fib.o ktiming.o getoptions.o fib-options.o
	$(CXX) $(FUTURE_CXXFLAGS) -c src/micro/old_micro.cpp -o old-micro.o
	$(CXX) -flto old-micro.o fib.o ktiming.o getoptions.o fib-options.o -o old-micro $(FUTURE_LDFLAGS)

TARGETS += micro-1prio
APPS += micro-1prio

micro-1prio: src/micro/micro.cpp fib.o ktiming.o getoptions.o fib-options.o
	$(CXX) $(FUTURE_CXXFLAGS) -DDONT_USE_PRIORITY_SCHEDULER -c src/micro/micro.cpp -o micro-1prio.o
	$(CXX) -flto micro-1prio.o fib.o ktiming.o getoptions.o fib-options.o -o micro-1prio $(FUTURE_LDFLAGS)

TARGETS += micro-noprio
APPS += micro-noprio

micro-noprio: src/micro/micro.cpp fib.o ktiming.o getoptions.o fib-options.o
	$(CXX) $(FUTURE_CXXFLAGS) -DDONT_USE_PRIORITY_SCHEDULER -DDONT_USE_PRIORITY -c src/micro/micro.cpp -o micro-noprio.o
	$(CXX) -flto micro-noprio.o fib.o ktiming.o getoptions.o fib-options.o -o micro-noprio $(FUTURE_LDFLAGS)

TARGETS += email
APPS += email

email: getoptions.o ../email/email.cpp ../email/email_cilksort.h ../email/email_cilksort.cpp ../email/inbox.h ../email/email_protocol.h ktiming.o
	$(CXX) $(FUTURE_CXXFLAGS) -c ../email/email.cpp -o email.o
	$(CXX) $(FUTURE_CXXFLAGS) -c ../email/email_cilksort.cpp -o email_cilksort.o
	$(CXX) $(FUTURE_CXXFLAGS) -c ../email/huffman.cpp -o huffman.o
	$(CXX) -flto email.o email_cilksort.o huffman.o ktiming.o getoptions.o -o email $(FUTURE_LDFLAGS)

TARGETS += email-noprio
APPS += email-noprio

email-noprio: getoptions.o ../email/email.cpp ../email/email_cilksort.h ../email/email_cilksort.cpp ../email/inbox.h ../email/email_protocol.h ktiming.o
	$(CXX) $(VANILLA_CXXFLAGS) -DNO_PRIO -c ../email/email.cpp -o email-noprio.o
	$(CXX) $(VANILLA_CXXFLAGS) -DNO_PRIO -c ../email/email_cilksort.cpp -o email_cilksort-noprio.o
	$(CXX) $(VANILLA_CXXFLAGS) -DNO_PRIO -c ../email/huffman.cpp -o huffman-noprio.o
	$(CXX) -flto email-noprio.o email_cilksort-noprio.o huffman-noprio.o ktiming.o getoptions.o -o email-noprio $(VANILLA_LDFLAGS)

TARGETS += email_driver
APPS += email_driver email_driver-noprio

email_driver: getoptions.o ../email/email_driver.cpp ../email/email_protocol.h ktiming.o
	$(CXX) -std=c++11 -O3 -flto -DNO_CILK -c ../email/email_driver.cpp -o email_driver.o
	$(CXX) -flto email_driver.o ktiming.o getoptions.o -o email_driver -lpthread -ltcmalloc

	#$(CXX) -flto email_driver.o ktiming.o getoptions.o -o email_driver -lpthread -L$(TCMALLOC_DIR) -ltcmalloc

#TARGETS += client
#APPS += client

#client: $(CILKPLUS_A) ../proxy/client.c
#	$(CXX) $(FUTURE_CXXFLAGS) -c ../proxy/client.c -o client.o
#	$(CXX) -flto client.o -o client $(FUTURE_LDFLAGS)


###########################################################################
# Though shalt not cross this line lest thou knowest what thou art doing! #
###########################################################################

all: $(TARGETS) 

clean:
	rm -f *.o $(APPS)
