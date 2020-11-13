#!/bin/bash

proxyfile_prio=proxy_results_prio.txt
driverfile_prio=driver_results_prio.txt
proxyfile_noprio=proxy_results_noprio.txt
driverfile_noprio=driver_results_noprio.txt
job_prio=job_results_prio.txt
job_noprio=job_results_noprio.txt
prio_results=proxy_prio_all_results.txt
noprio_results=proxy_noprio_all_results.txt

rm -f ${proxyfile_prio}
rm -f ${proxyfile_noprio}
rm -f ${driverfile_prio}
rm -f ${driverfile_noprio}
rm -f ${job_prio}
rm -f ${job_noprio}
rm -f ${prio_results}
rm -f ${noprio_results}
./test_proxy.sh
./test_job.sh
