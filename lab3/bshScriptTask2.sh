#!/bin/bash

CFILE="task2_read.c"
EXE="task2_read"
RESULTS="plotTimes.txt"

rm -f $RESULTS

sizes=(1 2 16 32 64 128 256 512 1024 2048 4096 8192)

for size in "${sizes[@]}"; do
	echo "Testing BUFFER-SIZE = $size"
	sed -i "s/#define BUFFER_SIZE .*/#define BUFFER_SIZE $size/" $CFILE
	gcc -Wall -pedantic -std=c99 -g $CFILE -o $EXE
	/usr/bin/time -f "$size %e" ./$EXE 2>> $RESULTS
done

echo "All tests complete. Reslts saved in $RESULTS"
