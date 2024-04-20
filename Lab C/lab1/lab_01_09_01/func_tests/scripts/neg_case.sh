#!/bin/bash

input_file="$1"

if test -f "$1"; then
    ../../app.exe < "$1" > /dev/null 2>&1
    if [ $? -eq 0 ]; then
        exit 1
    else
        exit 0
    fi
else
    echo "Error: file '$1' not found" >&2
    exit 1
fi

exit "$input_file"