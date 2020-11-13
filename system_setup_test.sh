#!/bin/bash

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m'

MAX_MAP_COUNT=$(sysctl -n vm.max_map_count)
if [ $MAX_MAP_COUNT -eq "1105490560" ];
then
  echo -e "$GREEN vm.max_map_count is set to $MAX_MAP_COUNT... $NC"
else
  echo -e "$RED vm.max_map_count is set to $MAX_MAP_COUNT (not 1105490560)! $NC"
  echo -e "$RED Please set using 'sudo sysctl -w vm.max_map_count=1105490560'$NC"
  echo ""
fi

HYPERTHREAD_COUNT=$(./threads_per_core_count.sh)
if [ $HYPERTHREAD_COUNT -eq "2" ];
then
  echo -e "$GREEN There are 2 hardware threads per core (hyperthreading is enabled)...$NC"
else
  echo ""
  echo -e "$RED There is/are $HYPERTHREAD_COUNT hardware thread(s) per core!$NC"
  echo -e "$RED This configuration is unlikely to work! Please run on a machine with hyperthreading support!$NC"
  echo ""
fi

CORE_COUNT=$(grep -c ^processor /proc/cpuinfo)
if [ $CORE_COUNT -ge "8" ];
then
  echo -e "$GREEN There are $CORE_COUNT processors (8 or more)...$NC"
else
  echo ""
  echo -e "$RED There are only $CORE_COUNT processors in the system! Ideally there should be $NC"
  echo -e "$RED at least 8. Our experiments were run with 80 (including hyperthreads) $NC"
  echo ""
fi

docker -v >/dev/null 2>&1
DOCKER_NOT_INSTALLED=$?

if [ $DOCKER_NOT_INSTALLED -eq "0" ];
then
  echo -e "$GREEN docker appears to be installed...$NC"
else
  echo ""
  echo -e "$RED docker is not installed! Please install the docker container system!$NC"
  echo -e "$RED Installation instructions can be found here: https://docs.docker.com/install/ $NC"
  echo ""
  exit
fi

CONTAINER_INSTALLED=$(expr $(docker image ls interactive-cilk | wc -l) - 1)
if [ $CONTAINER_INSTALLED -eq "1" ];
then
  echo -e "$GREEN interactive-cilk container is installed...$NC"
else
  echo ""
  echo -e "$RED interactive-cilk container is not installed!$NC"
  echo -e "$RED Install by running the install_container.sh script!$NC"
  echo ""
fi

IN_DOCKER_GROUP="0"
for GROUP in $(groups); do
  if [ "$GROUP" = "docker" ];
  then
    IN_DOCKER_GROUP="1"
    break
  fi
done

if [ $IN_DOCKER_GROUP -eq "1" ];
then
  echo -e "$GREEN user is in the docker group...$NC"
else
  echo -e "$YELLOW Not in docker group! Containers will be run as root!$NC"
  echo -e "$YELLOW Remedy by running 'sudo usermod -aG docker <your_username>'$NC"
  echo ""
fi

if [ $CONTAINER_INSTALLED ];
then
  RUN_DOCKER="docker run -u=$UID:$(id -g $USER) -it --security-opt seccomp=unconfined --rm -v$(pwd):/mnt/cilk-plus-futures -w=/mnt/cilk-plus-futures"
  if [ $IN_DOCKER_GROUP -eq "0" ];
  then
    RUN_DOCKER="sudo $RUN_DOCKER"
  fi

  pushd bench > /dev/null
  RESULT=$($RUN_DOCKER/bench interactive-cilk ./test_email.sh)
  echo -e "$RESULT"
  popd > /dev/null
  pushd proxy_and_jsched > /dev/null
  RESULT=$($RUN_DOCKER/proxy_and_jsched interactive-cilk ./test.sh)
  popd > /dev/null
  echo -e "$RESULT"
fi
