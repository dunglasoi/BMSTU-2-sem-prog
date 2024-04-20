#!/bin/bash
#
# Хуинь Вьет Хынг ИУ7-22Б, ИУ7И-27Б
#
# Functional negative test program with argument
#

usage="usage: neg_case file_stream_in file_stream_out_expect [-v]"

print_error() {
    echo "file_in: $file_in"
    echo "return_code: $ret_code"
    echo "file_out: $file_out != $file_expect"
}

# error: wrong parameter count
if [[ $# -lt 2 || $# -gt 3 ]]; then
    echo "neg_case: Wrong parameter count"
    echo "$usage"
    exit 2
fi

# error: wrong option
if [[ $# -eq 3 && $3 != "" && $3 != "-v" ]]; then
    echo "neg_case: Wrong option"
    echo "$usage"
    exit 3
fi

# filename
file_in=$1
file_expect=$2
file_exe=./app.exe
file_out=/tmp/"$(basename "$file_expect")"

# not file
if [[ ! -f $file_in || ! -f $file_exe ]]; then
    echo "neg_case: Missing file"
    exit 4
fi

# run app
$file_exe "$file_in" >"$file_out"
ret_code=$?
if [[ $ret_code -eq 0 ]]; then
    print_error
    exit 5
fi

if [[ $3 = "-v" ]]; then
    echo "return code: $ret_code"
fi

# compare result
if [[ $ret_code -eq 100 ]]; then
    ./func_tests/scripts/comparator.sh "$file_out" "$file_expect" "$3"
    ret_code=$?
    if [[ $ret_code -ne 0 ]]; then
        print_error
    fi
    exit $ret_code
else
    # compare error message
    ../common/src/cmp_after_str.sh "$file_out" "$file_expect" "Error:" "$3"
    ret_code=$?
    if [[ $ret_code -ne 0 ]]; then
        print_error
    fi
    exit $ret_code
fi

exit 0
