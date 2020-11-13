#!/bin/bash
nwork=10 #nworkers
bgtime=10000000 #interval for stats (1 sec/bgtime is freq)
sitenum=4096 #number of unique sites
reqnum=30 #requests per client
ltime=3 #sleep between runs
port=6789 #port for proxy IO
pmode=--test #send back yes/no == --test (--real for full site)
site_src=drivercode/run_sites/disk_source.txt #website list
rseed=90 #random number seed
hyper_threaded=$(../threads_per_core_count.sh)
ncores=$(grep -c ^processor /proc/cpuinfo)
nextsocket=0

# switch these 2 to enable/disable prefetching sites
PREFETCH="--prefetch"
#PREFETCH=""

quarter_cores=$(expr $ncores \/ 4)

if [ $quarter_cores -le $nwork ];
then
  nwork=$quarter_cores
fi

if [ $hyper_threaded == 2 ]; then
    nextsocket=$((ncores/hyper_threaded))
    nwork=$((nwork*hyper_threaded))
fi

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m'

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

FAILURE="0"

if [ $run_prio -eq 1 ]; then
    incr=0
    for cons in 10; do
	for util in .9; do
	    for rho in 2; do
		for qnl in 500; do
		    CILK_NWORKERS=$nwork ./proxy-prio --seed $rseed $pmode --port $port --cons $cons --bgsec $bgtime --rnum $incr --quantlen $qnl --cilkrho $rho --cilkutil $util > /dev/null &
		    sleep $ltime;
		    ./drivercode/con --trace $site_src --sites $sitenum --requests $reqnum --port $port -t $cons --seed $rseed $PREFETCH --nworkers $nwork --nexts $nextsocket --ondisk --rnum $incr > /dev/null
        FAILURE=$?
		    sleep $ltime;
		    ./kp.sh proxy-prio;
		    sleep $ltime;
		    incr=$((incr+1));
		done;
	    done;
	done;
    done; 
fi

if [ $FAILURE -eq "0" ];
then
  echo -e "$GREEN Able to run proxy-prio... $NC"
else
  echo ""
  echo -e "$RED Unable to run proxy-prio! Try rebuilding using setup.sh! $NC"
  echo ""
fi

if [ $run_noprio -eq 1 ]; then
    incr=0
    for cons in 10; do
	CILK_NWORKERS=$nwork ./proxy-noprio --seed $rseed $pmode --port $port --cons $cons --bgsec $bgtime --rnum $incr >/dev/null &
	sleep $ltime;
	./drivercode/con --trace $site_src --sites $sitenum --requests $reqnum --port $port -t $cons --seed $rseed $PREFETCH --nworkers $nwork --nexts $nextsocket --ondisk --rnum $incr > /dev/null
  FAILURE=$?
	sleep $ltime;
	./kp.sh proxy-noprio;
	incr=$((incr+1));
    done;
fi

if [ $FAILURE -eq "0" ];
then
  echo -e "$GREEN Able to run proxy-noprio... $NC"
else
  echo ""
  echo -e "$RED Unable to run proxy-noprio! Try rebuilding using setup.sh! $NC"
  echo ""
fi
