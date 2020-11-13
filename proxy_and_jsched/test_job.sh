#!/bin/bash
nwork=20 #nworkers
dtime=5 #runtime job benchmark
rseed=90 #random number seed
hyper_threaded=$(../threads_per_core_count.sh)
ncores=$(grep -c ^processor /proc/cpuinfo)

if [ $hyper_threaded == 2 ]; then
    nwork=$((nwork*hyper_threaded))
fi

if [ $ncores -le $nwork ];
then
  nwork=$ncores
fi

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m'

./kp.sh jsched-prio;
./kp.sh jsched-noprio;


#export LD_LIBRARY_PATH=$(pwd)/../gperftools-2.7/.libs

job_prio=job_results_prio.txt
job_noprio=job_results_noprio.txt
FAILURE="0"

for util in .9; do
    for rho in 2; do
	for qnl in 500; do
	    for freq in 3; do
		  CILK_NWORKERS=$nwork ./jsched-prio -f0 $freq -f1 $freq -f2 $freq -f3 $freq --seed $rseed --duration $dtime --quantlen $qnl --cilkrho $rho --cilkutil $util > /dev/null
      FAILURE=$?
	    done;
	done;
    done;
done;

if [ $FAILURE -eq "0" ];
then
  echo -e "$GREEN Able to run jsched-prio... $NC"
else
  echo ""
  echo -e "$RED Unable to run jsched-prio! Try rebuilding using setup.sh! $NC"
  echo ""
fi


for freq in 3; do
        CILK_NWORKERS=$nwork ./jsched-noprio -f0 $freq -f1 $freq -f2 $freq -f3 $freq --seed $rseed --duration $dtime > /dev/null
        FAILURE=$?
done;

if [ $FAILURE -eq "0" ];
then
  echo -e "$GREEN Able to run jsched-noprio... $NC"
else
  echo ""
  echo -e "$RED Unable to run jsched-noprio! Try rebuilding using setup.sh! $NC"
  echo ""
fi
