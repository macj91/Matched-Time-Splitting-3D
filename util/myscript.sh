#!/bin/sh
# script to run the foo program on dmc

#source /opt/asn/etc/asn-bash-profiles-special/modules.sh
#module load gcc/6.1.0

mkdir result && mkdir build && cd build && cmake .. && make -j8 && cd ..

./lastpaper
