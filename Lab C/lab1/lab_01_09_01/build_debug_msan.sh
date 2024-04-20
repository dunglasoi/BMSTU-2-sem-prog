#!/bin/bash

if ! clang -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer -g main.c -o app_ms.exe; then
    echo "Compilation failed. Exiting..."
    exit 1
else
    echo "Compilation successful"
fi

if ! clang main.c -o app.exe -lm; then
    echo "Linking failed. Exiting..."
    exit 1
else   
    echo "Linking successful"
fi