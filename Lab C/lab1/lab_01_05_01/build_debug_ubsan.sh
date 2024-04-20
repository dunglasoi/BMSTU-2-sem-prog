#!/bin/bash

if clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fsanitize=undefined -fno-omit-frame-pointer -g main.c; then
    echo "Compilation successful"
else
    echo "Compilation failed. Exiting..."
    exit 1
fi 

if clang main.c -o app.exe -lm; then
    echo "Linking successful"
else
    echo "Linking failed. Exiting..."
    exit 1
fi