#!/bin/bash

cmp=../../src/cmp_int.sh

echo "Positive tests"

for i in {01..05}; do
    file1=./data/pos_"$i"_file1.txt
    file2=./data/pos_"$i"_file2.txt
    $cmp $file1 $file2 -v
done

echo ""
echo "Negative tests"

for i in {01..04}; do
    file1=./data/neg_"$i"_file1.txt
    file2=./data/neg_"$i"_file2.txt
    $cmp $file1 $file2 -v
done
