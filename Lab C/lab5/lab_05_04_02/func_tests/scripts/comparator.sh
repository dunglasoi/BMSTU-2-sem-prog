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

diff "$file1" "$file2"
