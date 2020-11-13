CC = gcc
#CXX = g++
CFLAGS = -O3 -g -std=c11 -D_GNU_SOURCE
LDLIBS = -lpthread -lm #-lgsl -lgslcblas
all: con



con: con.o utils/arg.o utils/util.o utils/timing.o common/ktiming.o common/ktiming.h utils/stat.h

utils/arg.o: utils/arg.c utils/arg.h
utils/util.o: utils/util.c utils/util.h utils/stat.h
utils/timing.o: utils/timing.c utils/timing.h utils/util.h
common/ktiming.o: common/ktiming.c common/ktiming.h

clean: 
	rm -f  *~ con *.o \#* utils/*~ utils/*.o utils/\#* common/*~ common/*.o common/\#*
