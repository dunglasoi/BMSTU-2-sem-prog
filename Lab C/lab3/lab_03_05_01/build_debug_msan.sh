#!/bin/bash

if clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer -g main.c; then
    echo "Compilation successful"
else
    echo "Compilation failed"
    exit 1
fi

if clang *.c -o app.exe -lm; then
    echo "Linking successful"
else
    echo "Linking failed"
    exit 1
fi