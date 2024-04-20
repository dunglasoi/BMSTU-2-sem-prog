#!/bin/bash
#
# Хуинь Вьет Хынг ИУ7-22Б, ИУ7И-27Б
#
# Functional positive test program with binary file
#

usage="usage: pos_case file_stream_in file_stream_out_expect file_args [-v]"

print_error() {
    echo "file_in: $file_in"
    echo "return_code: $ret_code"
    echo "file_out: $file_out != $file_expect"
}

# error: wrong parameter count
if [[ $# -lt 3 || $# -gt 4 ]]; then
    echo "pos_case: Wrong parameter count"
    echo "$usage"
    exit 2
fi

# error: wrong option
if [[ $# -eq 4 && $4 != "" && $4 != "-v" ]]; then
    echo "pos_case: Wrong option"
    echo "$usage"
    exit 3
fi

# filename
file_in=$1
# file_in_bin=/tmp/"$(basename "$file_in" .txt).bin"
file_expect=$2
file_exe=./app.exe
file_out=/tmp/"$(basename "$file_expect")"
# file_out_bin=/tmp/"$(basename "$file_expect" .txt).bin"
# file_args=$3

# not file
if [[ ! -f $file_in || ! -f $file_expect || ! -f $file_exe ]]; then
    echo "pos_case: Missing file"
    exit 4
fi

# run app
./func_tests/scripts/pos_process.sh "$@"
ret_code=$?

if [[ $ret_code -ne 0 ]]; then
    print_error
    exit 5
fi

# compare result
./func_tests/scripts/comparator.sh "$file_out" "$file_expect" "$4"
ret_code=$?
if [[ $ret_code -ne 0 ]]; then
    print_error
fi

exit $ret_code
