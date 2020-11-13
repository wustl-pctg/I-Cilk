#!/bin/bash
nwork=20 #nworkers
bgtime=10000000 #interval for stats (1 sec/bgtime is freq)
sitenum=4096 #number of unique sites
reqnum=1500 #requests per client
ltime=5 #sleep between runs
port=6005 #port for proxy IO
pmode=--test #send back yes/no == --test (--real for full site)
site_src=drivercode/run_sites/disk_source.txt #website list
rseed=90 #random number seed
hyper_threaded=$(../threads_per_core_count.sh)
ncores=$(grep -c ^processor /proc/cpuinfo)
nextsocket=0

quarter_cores=$(expr $ncores \/ 4)

if [ $quarter_cores -le $nwork ];
then
  nwork=$quarter_cores
fi


# switch these 2 to enable/disable prefetching sites
PREFETCH="--prefetch"
#PREFETCH=""

# we need to double the number of workers;
# half will be dedicated to I/O on the 2nd hyperthread
if [ $hyper_threaded == 2 ]; then
    nextsocket=$((ncores/hyper_threaded))
    nwork=$((nwork*hyper_threaded))
fi


# Scale the number of clients; we had 90, 120, 150, 180 users per 40 "nwork" (20 * 2, hyperthreading)
NUM_CLIENTS=$(expr 90 \* $nwork \/ 40)
NUM_CLIENTS="$NUM_CLIENTS $(expr 120 \* $nwork \/ 40)"
NUM_CLIENTS="$NUM_CLIENTS $(expr 150 \* $nwork \/ 40)"
NUM_CLIENTS="$NUM_CLIENTS $(expr 180 \* $nwork \/ 40)"

# Scale the number of requests
reqnum=$(expr $reqnum \* $nwork \/ 40)

./kp.sh proxy-prio;
./kp.sh proxy-noprio;

#export LD_LIBRARY_PATH=$(pwd)/../gperftools-2.7/.libs

run_prio=1
run_noprio=1


proxyfile_prio=proxy_results_prio.txt
driverfile_prio=driver_results_prio.txt
proxyfile_noprio=proxy_results_noprio.txt
driverfile_noprio=driver_results_noprio.txt
prio_results=proxy_prio_all_results.txt
noprio_results=proxy_noprio_all_results.txt

if [ $run_prio -eq 1 ]; then
    incr=0
    for cons in $NUM_CLIENTS; do
	for util in .9; do
	    for rho in 2; do
		for qnl in 500; do
		    echo "Starting proxy(priority version): clients=${cons}, cilk_util=${util}, cilk_rho=${rho}, cilk_quant_length=${qnl}, outfile=${proxyfile_prio}"
		    CILK_NWORKERS=$nwork ./proxy-prio --seed $rseed $pmode --port $port --cons $cons --bgsec $bgtime --rnum $incr --quantlen $qnl --cilkrho $rho --cilkutil $util | tee -a $proxyfile_prio &
		    sleep $ltime;
		    echo "Starting driver: connections=${cons}, num_sites=${sitenum}, site_source=${site_src}, num_requests_per_con=${reqnum}, outfile=${driverfile_prio}"
		    ./drivercode/con --trace $site_src --sites $sitenum --requests $reqnum --port $port -t $cons --seed $rseed $PREFETCH --nworkers $nwork --nexts $nextsocket --ondisk --rnum $incr | tee -a $driverfile_prio
		    sleep $ltime;
		    ./kp.sh proxy-prio;
		    sleep $ltime;
		    incr=$((incr+1));
		done;
	    done;
	done;
    done; 
fi
if [ $run_noprio -eq 1 ]; then
    incr=0
    for cons in $NUM_CLIENTS; do
	echo "Starting proxy(no priority version): clients=${cons}, outfile=${proxyfile_noprio}"
	CILK_NWORKERS=$nwork ./proxy-noprio --seed $rseed $pmode --port $port --cons $cons --bgsec $bgtime --rnum $incr| tee -a $proxyfile_noprio &
	sleep $ltime;
	echo "Starting driver: connections=${cons}, num_sites=${sitenum}, site_source=${site_src}, num_requests_per_con=${reqnum}, outfile=${driverfile_noprio}"
	./drivercode/con --trace $site_src --sites $sitenum --requests $reqnum --port $port -t $cons --seed $rseed $PREFETCH --nworkers $nwork --nexts $nextsocket --ondisk --rnum $incr | tee -a $driverfile_noprio
	sleep $ltime;
	./kp.sh proxy-noprio;
	incr=$((incr+1));
    done;
fi
echo "Moving all proxy-prio data into $prio_results"
./combine.py -f2 $proxyfile_prio -f1 $driverfile_prio -o $prio_results
echo "Moving all proxy-noprio data into $noprio_results"
./combine.py -f2 $proxyfile_noprio -f1 $driverfile_noprio -o $noprio_results


