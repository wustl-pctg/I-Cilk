#!/bin/bash

#export LD_LIBRARY_PATH=$(pwd)/../gperftools-2.7/.libs

HYPERTHREAD_COUNT=$(../threads_per_core_count.sh)

QUANT_L="500"
RHO="2"
#MSGS=$(expr 3000 \* 90)
#NUM_CLIENTS="90 120 150 180"
COMPRESS_PERIOD_US=250000
PORT="9001"


PROCS_IN_SYS=$(grep -c ^processor /proc/cpuinfo)
PROCS=20
QUARTER_PROCS=$(expr $PROCS_IN_SYS \/ 4)

if [ $QUARTER_PROCS -le $PROCS ];
then
  PROCS=$QUARTER_PROCS
fi

DRIVER_PROCS=""

if [ ! $HYPERTHREAD_COUNT -eq "1" ]
then
  DRIVER_PROCS="$PROCS-$(expr $(expr $PROCS_IN_SYS \/ 2) - 1),$(expr $PROCS_IN_SYS - $PROCS)-$(expr $PROCS_IN_SYS - 1)"
  PROCS=$(expr $PROCS \* 2)
else
  DRIVER_PROCS="$PROCS-$(expr $PROCS_IN_SYS - 1)"
fi

# Scale the number of clients; we had 90, 120, 150, 180 users per 40 "PROCS"
NUM_CLIENTS=$(expr 90 \* $PROCS \/ 40)
NUM_CLIENTS="$NUM_CLIENTS $(expr 120 \* $PROCS \/ 40)"
NUM_CLIENTS="$NUM_CLIENTS $(expr 150 \* $PROCS \/ 40)"
NUM_CLIENTS="$NUM_CLIENTS $(expr 180 \* $PROCS \/ 40)"

# Scale the number of messages
MSGS=$(expr 3000 \* 90 \* $PROCS \/ 40)

# Make sure the driver procs variable describes a valid CPU set
taskset -c $DRIVER_PROCS echo "Test" &> /dev/null
INVALID=$?
if [ $INVALID -eq "1" ]
then
  echo "ERROR: Invalid set of cpus for the driver ($DRIVER_PROCS); you may need to reduce the number of email PROCS ($PROCS)!"
  exit
fi


for L in $QUANT_L; do
  for R in $RHO; do
    for N in $NUM_CLIENTS; do
      AGAIN=1
      TRIES=10
      while [ $AGAIN -eq 1 -a $TRIES -ge 1 ]; do
        echo " L $L, rho $R, util 0.9, Clients $N, Messages $MSGS, CompPeriod $COMPRESS_PERIOD_US, CompChunk 10" | tee tmp_email.txt tmp_driver.txt
        echo "Procs $(expr $PROCS \/ $HYPERTHREAD_COUNT)" | tee -a tmp_email.txt tmp_driver.txt

        taskset -c $DRIVER_PROCS ./email_driver -clients $N -messages $(expr $MSGS / $N) -port $PORT | tee -a tmp_driver.txt &

        CILK_NWORKERS=$PROCS ./email -L $L -rho $R -clients $N -messages $MSGS -compressChunk 10 -compressPeriodUs $COMPRESS_PERIOD_US -port $PORT | tee -a tmp_email.txt
        wait

        AGAIN=$(expr 1 - $(grep "comp (raw)" tmp_email.txt | wc -l))
        if [ $AGAIN -eq 0 ]
        then
          cat tmp_email.txt >> email_prio.txt
          cat tmp_driver.txt >> driver_prio.txt
        fi
        PORT=$(expr $PORT + 1)
        TRIES=$(expr $TRIES - 1)
      done
    done
  done
done

for N in $NUM_CLIENTS; do
  AGAIN=1
  TRIES=10
  while [ $AGAIN -eq 1 -a $TRIES -ge 1 ]; do
    echo "Clients $N, Messages $MSGS, CompPeriod $COMPRESS_PERIOD_US, CompChunk 10" | tee tmp_email.txt tmp_driver.txt
    echo "Procs $(expr $PROCS \/ $HYPERTHREAD_COUNT)" | tee -a tmp_email.txt tmp_driver.txt

    taskset -c $DRIVER_PROCS ./email_driver -clients $N -messages $(expr $MSGS / $N) -port $PORT | tee -a tmp_driver.txt &

    CILK_NWORKERS=$PROCS ./email-noprio -L 0 -rho 0 -clients $N -messages $MSGS -compressChunk 10 -compressPeriodUs $COMPRESS_PERIOD_US -port $PORT | tee -a tmp_email.txt
    wait

    AGAIN=$(expr 1 - $(grep "comp (raw)" tmp_email.txt | wc -l))
    if [ $AGAIN -eq 0 ]
    then
      cat tmp_email.txt >> email_noprio.txt
      cat tmp_driver.txt >> driver_noprio.txt
    fi
    PORT=$(expr $PORT + 1)
    TRIES=$(expr $TRIES - 1)
  done
done

rm tmp_email.txt
rm tmp_driver.txt
