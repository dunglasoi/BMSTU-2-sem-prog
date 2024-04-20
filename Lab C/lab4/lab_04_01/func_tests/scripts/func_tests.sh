#!/bin/bash

failed=0

files=( ../data/pos_*_in.txt )
i=0

while [ $i -lt ${#files[@]} ]; do
    in_file=${files[$i]}
    test_num=${in_file##*pos_}  # удаляем все символы до последнего вхождения "pos_"
    test_num=${test_num%%_in.txt}  # удаляем все символы после "_in.txt"

    while [ -z "$test_num" ]; do
        echo "There are no positive tests!"
        break
    done

    out_file="../data/pos_${test_num}_out.txt"

    if ./pos_case.sh "$in_file" "$out_file" ; then
        echo "test_pos_""$test_num"": PASSED"
    else
        failed=$((failed + 1))
        echo "test_pos_""$test_num"": FAILED"
    fi

    i=$((i + 1))
done

files=( ../data/neg_*_in.txt )
i=0
while [ $i -lt ${#files[@]} ]; do
    in_file=${files[$i]}
    test_num=${in_file##*neg_}  # удаляем все символы до последнего вхождения "neg_"
    test_num=${test_num%%_in.txt}  # удаляем все символы после "_in.txt"

    while [ -z "$test_num" ]; do
        echo "There are no positive tests!"
        break
    done

    out_file="../data/neg_""$test_num""_out.txt"

    if ./neg_case.sh "$in_file" "$out_file" ; then
        echo "test_neg_""$test_num"": PASSED"
    else
        failed=$((failed + 1))
        echo "test_neg_""$test_num"": FAILED"
    fi

    i=$((i + 1))
done

