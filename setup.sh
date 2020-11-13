#!/bin/bash
set -e

if [[ $(grep docker /proc/1/cgroup) == "" ]]; then
  echo "Attempting to run this script in the repo's docker container!"
  echo "Please: 1) install the docker container system,"
  echo "        2) install our docker image by running './build_docker.sh',"

  GROUP_LIST=$(groups)
  if [ $(echo $GROUP_LIST | grep docker | wc -l) == 1 ]; then
    docker run -u=$UID:$(id -g $USER) -it --security-opt seccomp=unconfined --rm -v$(pwd):/mnt/cilk-plus-futures -w=/mnt/cilk-plus-futures interactive-cilk ./setup.sh
  else
    echo "User not in group docker (run 'sudo usermod -aG docker <username>' to remedy)"
    echo "Requesting sudo permissions to run docker"
    sudo docker run -u=$UID:$(id -g $USER) -it --security-opt seccomp=unconfined --rm -v$(pwd):/mnt/cilk-plus-futures -w=/mnt/cilk-plus-futures interactive-cilk ./setup.sh
  fi

  exit
fi

BASE_DIR=$(pwd)
rm -f setup.log

function msg() {
    echo "$msg" | tee -a setup.log
}

msg "Begin PORRidge setup at $(date)"

: ${BINUTILS_PLUGIN_DIR:="/usr/include"}
if [[ ($BINUTILS_PLUGIN_DIR != "") &&
          (-e $BINUTILS_PLUGIN_DIR/plugin-api.h) ]]; then
    export LTO=1
else
    export LTO=0
    echo "Warning: no binutils plugin found, necessary for LTO"
fi

# Setup and compile our compiler, if not done already
if [[ ! (-e Tapir/src/build/bin/clang) ]]; then
  ./build-llvm-linux.sh
fi

msg "Tapir clang compiled."

# # Build the runtime (ability to suspend/resume deques)
cd ./cilk-l
rm -rf .deps/
libtoolize
autoreconf -i
./remake.sh opt lto
cd -

cd ./interactive-cilk
rm -rf .deps/
libtoolize
autoreconf -i
./remake.sh opt lto
cd -

msg "Suspendable work-stealing runtime built"

BASE_DIR=$(pwd)
if [ ! -e config.mk ]; then
    echo "BUILD_DIR=$BASE_DIR/build" >> config.mk
    echo "RUNTIME_HOME=$BASE_DIR/cilk-f" >> config.mk
    echo "COMPILER_HOME=$BASE_DIR/Tapir/build" >> config.mk
    echo "RTS_LIB=\$(COMPILER_HOME)/lib/libcilkrts.a" >> config.mk
    echo "LTO=$LTO" >> config.mk
fi

pushd bench
make clean
make
popd

pushd proxy_and_jsched
make clean
make
popd

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

HYPERTHREAD_COUNT=$(./threads_per_core_count.sh)
if [ $HYPERTHREAD_COUNT -eq "2" ]
then
  echo -e "${GREEN}Hyperthreading is ENABLED! Half the cores in the Cilk runtime will be used for I/O, and half for work."
  echo -e "If workers are specified with CILK_NWORKERS=20, for example, 10 cores will be used for computations.${NC}"
else
  echo -e "${RED}Hyperthreading is either DISABLED or there are more than 2 hyperthreads per core! All cores will be used"
  echo -e "for both computation and I/O, relying on the OS to switch between the 2 threads. If CILK_NWORKERS=20, then"
  echo -e "all 20 cores will be used for both I/O and computation."
  echo -e "Disabled hyperthreading is not thoroughly tested; having more than 2 hyperthreads is NOT SUPPORTED!${NC}"
fi
