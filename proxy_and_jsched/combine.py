#! /usr/bin/env python

import sys
import argparse
import os


def get_run_num(line_arr, search):
    for i in range(0, len(line_arr)-1):
        if search in line_arr[i]:
            return int(line_arr[i+1])
    print("Error cant find run number!")
    sys.exit(0)
                    

parser = argparse.ArgumentParser(description='Combine the csv from proxy and driver results')
parser.add_argument("-v",
                    "--verbosity",
                    action="count",
                    default=0,
                    help="increase output verbosity")
parser.add_argument("-f1",
                    "--file1",
                    default="",
                    help="First file to combine")
parser.add_argument("-f2",
                    "--file2",
                    default="",
                    help="Second file to combine")
parser.add_argument("-o",
                    "--outfile",
                    default="",
                    help="Output file from combining the csv in f1 and f2")


flags = parser.parse_args()
verbose = flags.verbosity
f1_name = flags.file1
f2_name = flags.file2
out_name = flags.outfile

if f1_name == "" or f2_name == "" or out_name == "":
    print("Error, not all files specified")
    sys.exit(0)

try:
    f1 = open(f1_name)
    # Do something with the file
except IOError:
    print("Cant open " + f1_name)
    sys.exit(0)

try:
    f2 = open(f2_name)
    # Do something with the file
except IOError:
    print("Cant open " + f2_name)
    sys.exit(0)

headers = {}
runs = {}

cur_run = 0
start_adding = 0


for lines in f1:
    if "Event," in lines:
        start_adding = 1
        runs[cur_run] = []
        runs[cur_run].append(lines)
        continue
    if "./" in lines:
        cur_run = get_run_num(lines.split(), "rnum")
        headers[cur_run] = []
        headers[cur_run].append(lines)
        start_adding = 0
        continue
    if "Avg Util" in lines:
        start_adding = 0
        continue
    if start_adding == 1:
        if "Tim" not in lines:
            continue
        runs[cur_run].append(lines)
        continue
    
expected_runs = cur_run
cur_run = 0
start_adding = 0
for lines in f2:
    if "Event," in lines:
        start_adding = 1
        continue
    if "./" in lines:
        cur_run = get_run_num(lines.split(), "rnum")
        headers[cur_run].append(lines)
        start_adding = 0
        continue
    if "Avg Util" in lines:
        start_adding = 0
        continue
    if start_adding == 1:
        if "Tim" not in lines:
            continue
        runs[cur_run].append(lines)
        continue
assert expected_runs == cur_run


try:
    out_file = open(out_name, "w+")
except IOError:
    print("Cant open " + out_name)
    sys.exit(0)

for i in range(0, cur_run + 1):
    line = ""
    run_info = headers[i]
    for l in range(0, len(run_info)):
        line += run_info[l]
    run_info = runs[i]
    for l in range(0 , len(run_info)):
        line += run_info[l]
    out_file.write(line + "\n")
