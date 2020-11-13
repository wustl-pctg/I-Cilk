#!/bin/bash

if [[ $(grep docker /proc/1/cgroup) == "" ]]; then
  echo "About to attempt to run this script in the repo's docker container!"
  echo "If this fails, make sure that you have done the following:"
  echo "        1) installed the docker container system,"
  echo "        2) installed our docker image by running './build_docker.sh',"
  echo "           or by running './install_container.sh' from the I-Cilk"
  echo "           directory."

  GROUP_LIST=$(groups)
  if [ $(echo $GROUP_LIST | grep docker | wc -l) == 1 ]; then
    docker run -u=$UID:$(id -g $USER) -it --security-opt seccomp=unconfined --rm -v$(pwd):/mnt/cilk-plus-futures -w=/mnt/cilk-plus-futures interactive-cilk ./collect_artifact_data.sh
  else
    echo "User not in group docker (run 'sudo usermod -aG docker <username>' to remedy)"
    echo "Requesting sudo permissions to run docker"
    sudo docker run -u=$UID:$(id -g $USER) -it --security-opt seccomp=unconfined --rm -v$(pwd):/mnt/cilk-plus-futures -w=/mnt/cilk-plus-futures interactive-cilk ./collect_artifact_data.sh
  fi

  exit
fi

#./setup.sh

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

OUTPUT_DIR="./data/data_$(date +"%Y-%m-%d-%H_%M_%S")"

mkdir -p $OUTPUT_DIR/email
mkdir -p $OUTPUT_DIR/proxy
mkdir -p $OUTPUT_DIR/jsched

rm -f latest_data
ln -rs $OUTPUT_DIR latest_data

# Generate figure 7
./time_compilations.sh

pushd bench
rm ./*.txt
# Run all the email benchmark configurations
./run_email.sh
# Copy the output of the email benchmarks to the data folder
cp *.txt $SCRIPT_DIR/$OUTPUT_DIR/email/
popd

pushd proxy_and_jsched
# Run all the proxy and job server benchmark configurations
./run.sh
cp ./*proxy*.txt $SCRIPT_DIR/$OUTPUT_DIR/proxy
cp ./*driver*.txt $SCRIPT_DIR/$OUTPUT_DIR/proxy
cp ./*job*.txt $SCRIPT_DIR/$OUTPUT_DIR/jsched
popd

pushd $OUTPUT_DIR
pushd email
# Parse the email output into csvs
$SCRIPT_DIR/parse_scripts/email_parse.py
mkdir raw
mv ./*.txt raw/
popd

pushd jsched
grep -v "Util\|Highest\|Avg L\|Offset:\|Using" ./job_results_prio.txt | sed -e "1 ! s/\.\/jsched/\n\.\/jsched/" > job_results_prio.csv
grep -v "Util\|Highest\|Avg L\|Offset:\|Using" ./job_results_noprio.txt | sed -e "1 ! s/\.\/jsched/\n\.\/jsched/" > job_results_noprio.csv
mkdir raw
mv ./*.txt raw/
popd

pushd proxy
grep -v "Util\|Highest\|Avg L\|Offset:\|Using" ./proxy_prio_all_results.txt > proxy_results_prio.csv
grep -v "Util\|Highest\|Avg L\|Offset:\|Using" ./proxy_noprio_all_results.txt > proxy_results_noprio.csv
mkdir raw
mv ./*.txt raw/
popd

popd

echo "Copied the spreadsheet template into the data directory."
echo "NOTE: The spreadsheet is NOT updated; this must be done manually."
cp $SCRIPT_DIR/figures_8-9_template.ods $SCRIPT_DIR/$OUTPUT_DIR/figures_8-9.ods
