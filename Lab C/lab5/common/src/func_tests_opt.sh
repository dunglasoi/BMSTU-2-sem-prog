#!/bin/bash
#
# Хуинь Вьет Хынг ИУ7-22Б, ИУ7И-27Б
#
# Functional test program
#

usage="usage: func_tests file_args [-v]"

# error: wrong parameter count
if [[ $# -gt 2 ]]; then
    echo "func_tests: Wrong parameter count"
    echo "$usage"
    exit 2
fi

# error: wrong option
if [[ $# -eq 2 && $2 != "" && $2 != "-v" ]]; then
    echo "func_tests: Wrong option"
    echo "$usage"
    exit 3
fi

# positive tests
pos_total=0
pos_pass=0

for file_in in ./func_tests/data/"$1"*pos_*_in.txt; do
    pos_total=$(("$pos_total" + 1))
    ./func_tests/scripts/pos_case.sh "$file_in" "${file_in/"_in.txt"/"_out.txt"}" "$1" "$2"
    ret_code=$?
    if [[ $ret_code -eq 0 ]]; then
        pos_pass=$(("$pos_pass" + 1))
    fi
done

echo "Total positive test: $pos_total. Pass: $pos_pass."

# negative tests
neg_total=0
neg_pass=0

for file_in in ./func_tests/data/"$1"*neg_*_in.txt; do
    neg_total=$(("$neg_total" + 1))
    ./func_tests/scripts/neg_case.sh "$file_in" "${file_in/"_in.txt"/"_out.txt"}" "$1" "$2"
    ret_code=$?
    if [[ $ret_code -eq 0 ]]; then
        neg_pass=$(("$neg_pass" + 1))
    fi
done

echo "Total negative test: $neg_total. Pass: $neg_pass."

#
if [[ $pos_pass -ne $pos_total || $neg_pass -ne $neg_total ]]; then
    exit 1
fi
exit 0
