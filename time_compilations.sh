#!/bin/bash

if [[ $(grep docker /proc/1/cgroup) == "" ]]; then
  GROUP_LIST=$(groups)
  if [ $(echo $GROUP_LIST | grep docker | wc -l) == 1 ]; then
    docker run -u=$UID:$(id -g $USER) -it --security-opt seccomp=unconfined --rm -v$(pwd):/mnt/cilk-plus-futures -w=/mnt/cilk-plus-futures interactive-cilk ./time_compilations.sh
  else
    echo "User not in group docker (run 'sudo usermod -aG docker <username>' to remedy)"
    echo "Requesting sudo permissions to run docker"
    sudo docker run -u=$UID:$(id -g $USER) -it --security-opt seccomp=unconfined --rm -v$(pwd):/mnt/cilk-plus-futures -w=/mnt/cilk-plus-futures interactive-cilk ./time_compilations.sh
  fi

  exit
fi

pushd bench
make clean > /dev/null
EMAIL_TIMES=$( (time -p make email > /dev/null) 2>&1)
make clean > /dev/null
EMAIL_TIMES=$"$EMAIL_TIMES\n$( (time -p make email > /dev/null) 2>&1)"
make clean > /dev/null
EMAIL_TIMES=$"$EMAIL_TIMES\n$( (time -p make email > /dev/null) 2>&1)"
EMAIL_TIMES=$"$(echo -e "$EMAIL_TIMES" | grep real)"
EMAIL_TIMES=$(echo -e "$EMAIL_TIMES" | sort -t ' ' -k 2 -g)

EMAIL_TIMES=$(echo -e "$EMAIL_TIMES" | tail -n 1)
PRIO_EMAIL=""
# should iterate 2 times; second time should get the time value
for each in $EMAIL_TIMES; do
  PRIO_EMAIL=$each
done

make clean > /dev/null
EMAIL_TIMES=$( (time -p make email-noprio > /dev/null) 2>&1)
make clean > /dev/null
EMAIL_TIMES=$"$EMAIL_TIMES\n$( (time -p make email-noprio > /dev/null) 2>&1)"
make clean > /dev/null
EMAIL_TIMES=$"$EMAIL_TIMES\n$( (time -p make email-noprio > /dev/null) 2>&1)"
EMAIL_TIMES=$"$(echo -e "$EMAIL_TIMES" | grep real)"
EMAIL_TIMES=$(echo -e "$EMAIL_TIMES" | sort -t ' ' -k 2 -g)

EMAIL_TIMES=$(echo -e "$EMAIL_TIMES" | tail -n 1)
NOPRIO_EMAIL=""
# should iterate 2 times; second time should get the time value
for each in $EMAIL_TIMES; do
  NOPRIO_EMAIL=$each
done

make &> /dev/null

PRIO_EMAIL_SIZE=$(wc -c email)
PRIO_EMAIL_SIZE=($PRIO_EMAIL_SIZE)
PRIO_EMAIL_SIZE=${PRIO_EMAIL_SIZE[0]}
PRIO_EMAIL_SIZE=$(python -c "print(\"%.1f\" % ($PRIO_EMAIL_SIZE / 1024.))")

NOPRIO_EMAIL_SIZE=$(wc -c email-noprio)
NOPRIO_EMAIL_SIZE=($NOPRIO_EMAIL_SIZE)
NOPRIO_EMAIL_SIZE=${NOPRIO_EMAIL_SIZE[0]}
NOPRIO_EMAIL_SIZE=$(python -c "print(\"%.1f\" % ($NOPRIO_EMAIL_SIZE / 1024.))")

popd

pushd proxy_and_jsched

make clean > /dev/null
PROXY_TIMES=$( (time -p make proxy-prio > /dev/null) 2>&1)
make clean > /dev/null
PROXY_TIMES=$"$PROXY_TIMES\n$( (time -p make proxy-prio > /dev/null) 2>&1)"
make clean > /dev/null
PROXY_TIMES=$"$PROXY_TIMES\n$( (time -p make proxy-prio > /dev/null) 2>&1)"
PROXY_TIMES=$"$(echo -e "$PROXY_TIMES" | grep real)"
PROXY_TIMES=$(echo -e "$PROXY_TIMES" | sort -t ' ' -k 2 -g)

PRIO_PROXY=""
# should iterate 2 times; second time should get the time value
for each in $PROXY_TIMES; do
  PRIO_PROXY=$each
done

make clean > /dev/null
PROXY_TIMES=$( (time -p make proxy-noprio > /dev/null) 2>&1)
make clean > /dev/null
PROXY_TIMES=$"$PROXY_TIMES\n$( (time -p make proxy-noprio > /dev/null) 2>&1)"
make clean > /dev/null
PROXY_TIMES=$"$PROXY_TIMES\n$( (time -p make proxy-noprio > /dev/null) 2>&1)"
PROXY_TIMES=$"$(echo -e "$PROXY_TIMES" | grep real)"
PROXY_TIMES=$(echo -e "$PROXY_TIMES" | sort -t ' ' -k 2 -g)

NOPRIO_PROXY=""
# should iterate 2 times; second time should get the time value
for each in $PROXY_TIMES; do
  NOPRIO_PROXY=$each
done

make clean > /dev/null
JOB_TIMES=$( (time -p make jsched-prio > /dev/null) 2>&1)
make clean > /dev/null
JOB_TIMES=$"$JOB_TIMES\n$( (time -p make jsched-prio > /dev/null) 2>&1)"
make clean > /dev/null
JOB_TIMES=$"$JOB_TIMES\n$( (time -p make jsched-prio > /dev/null) 2>&1)"
JOB_TIMES=$"$(echo -e "$JOB_TIMES" | grep real)"
JOB_TIMES=$(echo -e "$JOB_TIMES" | sort -t ' ' -k 2 -g)

PRIO_JOB=""
# should iterate 2 times; second time should get the time value
for each in $JOB_TIMES; do
  PRIO_JOB=$each
done

make clean > /dev/null
JOB_TIMES=$( (time -p make jsched-noprio > /dev/null) 2>&1)
make clean > /dev/null
JOB_TIMES=$"$JOB_TIMES\n$( (time -p make jsched-noprio > /dev/null) 2>&1)"
make clean > /dev/null
JOB_TIMES=$"$JOB_TIMES\n$( (time -p make jsched-noprio > /dev/null) 2>&1)"
JOB_TIMES=$"$(echo -e "$JOB_TIMES" | grep real)"
JOB_TIMES=$(echo -e "$JOB_TIMES" | sort -t ' ' -k 2 -g)

NOPRIO_JOB=""
# should iterate 2 times; second time should get the time value
for each in $JOB_TIMES; do
  NOPRIO_JOB=$each
done

make &> /dev/null

PRIO_PROXY_SIZE=$(wc -c proxy-prio)
PRIO_PROXY_SIZE=($PRIO_PROXY_SIZE)
PRIO_PROXY_SIZE=${PRIO_PROXY_SIZE[0]}
PRIO_PROXY_SIZE=$(python -c "print(\"%.1f\" % ($PRIO_PROXY_SIZE / 1024.))")

NOPRIO_PROXY_SIZE=$(wc -c proxy-noprio)
NOPRIO_PROXY_SIZE=($NOPRIO_PROXY_SIZE)
NOPRIO_PROXY_SIZE=${NOPRIO_PROXY_SIZE[0]}
NOPRIO_PROXY_SIZE=$(python -c "print(\"%.1f\" % ($NOPRIO_PROXY_SIZE / 1024.))")

PRIO_JOB_SIZE=$(wc -c jsched-prio)
PRIO_JOB_SIZE=($PRIO_JOB_SIZE)
PRIO_JOB_SIZE=${PRIO_JOB_SIZE[0]}
PRIO_JOB_SIZE=$(python -c "print(\"%.1f\" % ($PRIO_JOB_SIZE / 1024.))")

NOPRIO_JOB_SIZE=$(wc -c jsched-noprio)
NOPRIO_JOB_SIZE=($NOPRIO_JOB_SIZE)
NOPRIO_JOB_SIZE=${NOPRIO_JOB_SIZE[0]}
NOPRIO_JOB_SIZE=$(python -c "print(\"%.1f\" % ($NOPRIO_JOB_SIZE / 1024.))")

popd

EMAIL_TIME_OVERHEAD=$(python -c "print(\"(%.2fx)\" % ($PRIO_EMAIL / $NOPRIO_EMAIL))")
EMAIL_SIZE_OVERHEAD=$(python -c "print(\"(%.2fx)\" % ($PRIO_EMAIL_SIZE / $NOPRIO_EMAIL_SIZE))")

PROXY_TIME_OVERHEAD=$(python -c "print(\"(%.2fx)\" % ($PRIO_PROXY / $NOPRIO_PROXY))")
PROXY_SIZE_OVERHEAD=$(python -c "print(\"(%.2fx)\" % ($PRIO_PROXY_SIZE / $NOPRIO_PROXY_SIZE))")

JOB_TIME_OVERHEAD=$(python -c "print(\"(%.2fx)\" % ($PRIO_JOB / $NOPRIO_JOB))")
JOB_SIZE_OVERHEAD=$(python -c "print(\"(%.2fx)\" % ($PRIO_JOB_SIZE / $NOPRIO_JOB_SIZE))")

pwd

echo -e " case study  \t time (overhead) \t size (overhead)" | tee latest_data/figure7.txt
echo -e "proxy (w/out)\t$NOPRIO_PROXY s (1.00x)\t $NOPRIO_PROXY_SIZE KB (1.00x)" | tee -a latest_data/figure7.txt
echo -e "proxy (with)\t$PRIO_PROXY s $PROXY_TIME_OVERHEAD\t$PRIO_PROXY_SIZE KB $PROXY_SIZE_OVERHEAD" | tee -a latest_data/figure7.txt
echo -e "email (w/out)\t$NOPRIO_EMAIL s (1.00x)\t$NOPRIO_EMAIL_SIZE KB (1.00x)" | tee -a latest_data/figure7.txt
echo -e "email (with)\t$PRIO_EMAIL s $EMAIL_TIME_OVERHEAD\t$PRIO_EMAIL_SIZE KB $EMAIL_SIZE_OVERHEAD" | tee -a latest_data/figure7.txt
echo -e "jserver (w/out)\t$NOPRIO_JOB s (1.00x)\t $NOPRIO_JOB_SIZE KB (1.00x)" | tee -a latest_data/figure7.txt
echo -e "jserver (with)\t$PRIO_JOB s $JOB_TIME_OVERHEAD\t$PRIO_JOB_SIZE KB $JOB_SIZE_OVERHEAD" | tee -a latest_data/figure7.txt
