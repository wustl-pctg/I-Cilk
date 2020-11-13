#!/bin/bash

foo=$(pidof proxy-prio); for w in $foo; do echo $w; kill -9 $w; done;
foo=$(pidof proxy-noprio); for w in $foo; do echo $w; kill -9 $w; done;
