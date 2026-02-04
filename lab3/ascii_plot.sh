#!/bin/bash

DATAFILE="plotTimesFread.txt"
MAX_WIDTH=50  # maximum number of characters for the largest bar

if [ ! -f "$DATAFILE" ]; then
    echo "Error: $DATAFILE not found."
    exit 1
fi

# Find the maximum time for scaling
MAX_TIME=$(awk '{if($2>max) max=$2} END{print max}' $DATAFILE)

echo "ASCII Plot of Read Times (scaled to max $MAX_TIME s)"
echo "Buffer Size | Time (s) | Bar"
echo "---------------------------------------------"

while read SIZE TIME; do
    # Calculate number of '#' characters proportional to MAX_WIDTH
    BAR_LENGTH=$(awk -v t=$TIME -v m=$MAX_TIME -v w=$MAX_WIDTH 'BEGIN {printf "%d", (t/m)*w}')
    BAR=$(printf "%0.s#" $(seq 1 $BAR_LENGTH))
    printf "%10d | %8.2f | %s\n" $SIZE $TIME "$BAR"
done < $DATAFILE

