#!/bin/bash

if ! clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fsanitize=address -fno-omit-frame-pointer -g main.c -c -o main.o; then
    echo "Compilation failed. Exiting..."
    exit 1
else
    echo "Compilation successful"
fi

if clang main.o -o app.exe -lm; then
    echo "Linking successful"
else
    echo "Linking failed. Exiting..."
    exit 1
fi