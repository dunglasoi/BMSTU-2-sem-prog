#!/bin/bash

if gcc -c -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion main.c; then
    echo "Compilation successful"

if gcc main.o -o app.exe -lm; then
    echo "Linking successful"
else
    echo "Linking failed" >&2
    exit 1
fi
else
    echo "Compilation failed" >&2
    exit 1
fi