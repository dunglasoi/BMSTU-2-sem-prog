#!/bin/bash

# Program use cases
#

# filename
file_in=$1
file_in_bin=/tmp/"$(basename "$file_in" .txt).bin"
file_expect=$2
file_exe=./app.exe
file_out=/tmp/"$(basename "$file_expect")"
# file_out_bin=/tmp/"$(basename "$file_expect" .txt).bin"
file_args=$3

ret_code=0
# run app
if [[ "$file_args" = "p" ]]; then
    # transform text file to binary
    $file_exe t2b "$file_in" "$file_in_bin"

    $file_exe "$file_args" "$file_in_bin" >"$file_out"
    ret_code=$?

    if [[ $ret_code -eq 0 ]]; then
        # transform binary file to text
        $file_exe b2t "$file_in_bin" "$file_out"
    fi
elif [[ "$file_args" = "s" ]]; then
    # transform text file to binary
    $file_exe t2b "$file_in" "$file_in_bin"

    $file_exe s "$file_in_bin" >"$file_out"
    ret_code=$?

    if [[ $ret_code -eq 0 ]]; then
        # transform binary file to text
        $file_exe b2t "$file_in_bin" "$file_out"
    fi
fi

exit $ret_code
