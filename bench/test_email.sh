#!/bin/bash

HYPERTHREAD_COUNT=$(../threads_per_core_count.sh)

QUANT_L="500"
RHO="2"
MSGS=$(expr 1000)
NUM_CLIENTS="10"
COMPRESS_PERIOD_US=250000
#NUM_CLIENTS="90"
PORT="7668"

PROCS_IN_SYS=$(grep -c ^processor /proc/cpuinfo)
PROCS=20
QUARTER_PROCS=$(expr $PROCS_IN_SYS \/ 4)

if [ $QUARTER_PROCS -le $PROCS ];
then
  PROCS=$QUARTER_PROCS
fi

DRIVER_PROCS=""

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m'

if [ ! $HYPERTHREAD_COUNT -eq "1" ]
then
  DRIVER_PROCS="$PROCS-$(expr $(expr $PROCS_IN_SYS \/ 2) - 1),$(expr $PROCS_IN_SYS - $PROCS)-$(expr $PROCS_IN_SYS - 1)"
  PROCS=$(expr $PROCS \* 2)
else
  DRIVER_PROCS="$PROCS-$(expr $PROCS_IN_SYS - 1)"
fi

# Make sure the driver procs variable describes a valid CPU set
taskset -c $DRIVER_PROCS echo "Test" &> /dev/null
INVALID=$?
if [ $INVALID -eq "1" ]
then
  echo -e "$RED ERROR: Invalid set of cpus for the driver ($DRIVER_PROCS); you may need to reduce the number of email PROCS ($PROCS)! $NC"
  exit
fi

AGAIN=1

for L in $QUANT_L; do
  for R in $RHO; do
    for N in $NUM_CLIENTS; do
      AGAIN=1
      TRIES=10
      while [ $AGAIN -eq 1 -a $TRIES -ge 1 ]; do
        taskset -c $DRIVER_PROCS ./email_driver -clients $N -messages $(expr $MSGS / $N) -port $PORT > /dev/null &
        CILK_NWORKERS=$PROCS ./email -L $L -rho $R -clients $N -messages $MSGS -compressChunk 10 -compressPeriodUs $COMPRESS_PERIOD_US -port $PORT > tmp_email.txt
        wait
        AGAIN=$(expr 1 - $(grep "comp (raw)" tmp_email.txt | wc -l))
        PORT=$(expr $PORT + 1)
        TRIES=$(expr $TRIES - 1)
      done
    done
  done
done

if [ $AGAIN -eq "1" ];
then
  echo ""
  echo -e "$RED Unable to run email-prio! Try rebuilding using setup.sh! $NC"
  echo ""
else
  echo -e "$GREEN Able to run email-prio... $NC"
fi

for N in $NUM_CLIENTS; do
  AGAIN=1
  TRIES=10
  while [ $AGAIN -eq 1 -a $TRIES -ge 1 ]; do
    taskset -c $DRIVER_PROCS ./email_driver -clients $N -messages $(expr $MSGS / $N) -port $PORT > /dev/null &
    CILK_NWORKERS=$PROCS ./email-noprio -L 0 -rho 0 -clients $N -messages $MSGS -compressChunk 10 -compressPeriodUs $COMPRESS_PERIOD_US -port $PORT > tmp_email.txt
    wait
    AGAIN=$(expr 1 - $(grep "comp (raw)" tmp_email.txt | wc -l))
    PORT=$(expr $PORT + 1)
    TRIES=$(expr $TRIES - 1)
  done
done

if [ $AGAIN -eq "1" ];
then
  echo ""
  echo -e "$RED Unable to run email-noprio! Try rebuilding using setup.sh! $NC"
  echo ""
else
  echo -e "$GREEN Able to run email-noprio... $NC"
fi

rm *.txt
