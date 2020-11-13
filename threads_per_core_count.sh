#!/bin/sh

echo $(expr $(cat /sys/devices/system/cpu/cpu0/topology/thread_siblings_list | tr -cd , | wc -c) + 1)
