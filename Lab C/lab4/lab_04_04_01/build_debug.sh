#!/bin/bash
#

#
# Build program with debugging information

# Set default compile flags
FLAGS="-std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -Wvla -g -fprofile-arcs -ftest-coverage -lm"

# Compile all C source files in the current directory
gcc $FLAGS -c ./*.c

# Link object files into the executable
gcc $FLAGS -o app.exe ./*.o
