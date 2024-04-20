#!/bin/bash

failed=0

# Test for positive cases
for in_file in ../data/pos_*_in.txt; do
  test_num=${in_file##*pos_}  # Remove all characters before the last occurrence of "pos_"
  test_num=${test_num%%_in.txt}  # Remove all characters after "_in.txt"

  if [ -z "$test_num" ]; then
    echo "There are no positive tests!"
    break
  fi

  out_file="../data/pos_${test_num}_out.txt"

  if ./pos_case.sh "$in_file" "$out_file" ; then
    echo "test_pos_$test_num: PASSED"
  else
    ((failed++))
    echo "test_pos_$test_num: FAILED"
  fi
done

# Test for negative cases
for in_file in ../data/neg_*_in.txt; do
  test_num=${in_file##*neg_}  # Remove all characters before the last occurrence of "neg_"
  test_num=${test_num%%_in.txt}  # Remove all characters after "_in.txt"

  if [ -z "$test_num" ]; then
    echo "There are no negative tests!"
    break
  fi

  out_file="../data/neg_${test_num}_out.txt"

  if ./neg_case.sh "$in_file" "$out_file" ; then
    echo "test_neg_$test_num: PASSED"
  else
    ((failed++))
    echo "test_neg_$test_num: FAILED"
  fi
done

echo "Total failed tests: $failed"