#!/bin/bash
#
# Хуинь Вьет Хынг ИУ7-22Б, ИУ7И-27Б
#
# Build program with debugging information
#

if [[ $# -eq 1 ]]; then
    gcc "$1" \
        -std=c99 -Wall -Werror -Wextra -Wpedantic \
        -Wfloat-equal -Wfloat-conversion \
        -Wvla \
        -g \
        -fprofile-arcs -ftest-coverage \
        -c ./*.c

    gcc "$1" \
        -fprofile-arcs -ftest-coverage \
        -o app.exe ./*.o \
        -lm
else
    gcc \
        -std=c99 -Wall -Werror -Wextra -Wpedantic \
        -Wfloat-equal -Wfloat-conversion \
        -Wvla \
        -g \
        -fprofile-arcs -ftest-coverage \
        -c ./*.c

    gcc \
        -fprofile-arcs -ftest-coverage \
        -o app.exe ./*.o \
        -lm
fi
