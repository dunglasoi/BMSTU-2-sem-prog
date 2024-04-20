#!/bin/bash

FLAGS="-std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -O3 -lm"

gcc $FLAGS -c main.c
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

clang *.c -o app.exe -lm
if [ $? -ne 0 ]; then
    echo "Linking failed"
    exit 1
else
    echo "Compilation successful and linking successful"
fi
