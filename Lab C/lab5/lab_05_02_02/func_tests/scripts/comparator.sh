#!/usr/bin/env bash

usage () {
    echo "Usage: comparator file0 file1"
}

if [ "$#" -le 1 ]; then 
    usage
    exit 1
fi

file1="$1"
file2="$2"

if [ ! -f "$file1" ]; then 
    usage
    exit 1
fi 

if [ ! -f "$file2" ]; then 
    usage
    exit 1
fi 

NUM_REGEX="[+-]?([0-9]*[.]?[0-9]+|[0-9]+[.]?[0-9]*)"

mapfile -t seq1 < <(grep -Eo "$NUM_REGEX" "$file1")
mapfile -t seq2 < <(grep -Eo "$NUM_REGEX" "$file2")

n1=${#seq1[@]}
n2=${#seq2[@]}
if [ "$n1" -ne "$n2" ]; then 
    exit 1
fi

has_error=0
for i in "${!seq1[@]}"; do 
    it1=${seq1[i]}
    it2=${seq2[i]}
    if [ "$it1" != "$it2" ]; then
        has_error=1
        break
    fi
done

exit "$has_error"
