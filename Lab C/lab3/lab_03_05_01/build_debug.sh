#!/bin/bash

# Set default compile flags
FLAGS="-std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -g -fprofile-arcs -ftest-coverage -lm"

# Compile all C source files in the current directory into object files
for SOURCE_FILE in *.c
do
    OBJECT_FILE="${SOURCE_FILE%.c}.o"
    gcc $FLAGS -c "$SOURCE_FILE" -o "$OBJECT_FILE"
    if [ $? -ne 0 ]; then
        echo "Compilation failed"
        exit 1
    fi
done

# Link object files into the executable
gcc $FLAGS -o app.exe ./*.o
if [ $? -ne 0 ]; then
    echo "Linking failed"
    exit 1
else
    echo "Compilation successful and linking successful"
fi
