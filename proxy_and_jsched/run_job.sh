#!/bin/bash
nwork=20 #nworkers
dtime=15 #runtime job benchmark
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

./kp.sh jsched-prio;
./kp.sh jsched-noprio;


#export LD_LIBRARY_PATH=$(pwd)/../gperftools-2.7/.libs

job_prio=job_results_prio.txt
job_noprio=job_results_noprio.txt

for util in .9; do
    for rho in 2; do
	for qnl in 500; do
	    for freq in 2 3 4 5; do
		echo "Starting job(priority version): freq=${freq},  duration=${dtime}, cilk_util=${util}, cilk_rho=${rho}, cilk_quant_length=${qnl}, outfile=${job_prio}"
		CILK_NWORKERS=$nwork ./jsched-prio -f0 $freq -f1 $freq -f2 $freq -f3 $freq --seed $rseed --duration $dtime --quantlen $qnl --cilkrho $rho --cilkutil $util | tee -a $job_prio
	    done;
	done;
    done;
done;


for freq in 2 3 4 5; do
    	echo "Starting job(no priority version): freq=${freq}, duration=${dtime}, outfile=${job_noprio}"
        CILK_NWORKERS=$nwork ./jsched-noprio -f0 $freq -f1 $freq -f2 $freq -f3 $freq --seed $rseed --duration $dtime | tee -a $job_noprio
done;

