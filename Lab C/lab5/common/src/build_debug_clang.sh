#!/bin/bash
#
# Хуинь Вьет Хынг ИУ7-22Б, ИУ7И-27Б
#
# Build program with debugging information
#

if [[ $# -eq 1 ]]; then
    clang "$1" \
        -std=c99 -Wall -Werror -Wextra -Wpedantic -Wdocumentation \
        -Wfloat-equal -Wfloat-conversion \
        -Wvla \
        -fprofile-instr-generate -fcoverage-mapping \
        -c ./*.c

    clang "$1" \
        -fprofile-instr-generate -fcoverage-mapping -Wdocumentation \
        -o app.exe ./*.o \
        -lm
else
    clang \
        -std=c99 -Wall -Werror -Wextra -Wpedantic -Wdocumentation \
        -Wfloat-equal -Wfloat-conversion \
        -Wvla \
        -fprofile-instr-generate -fcoverage-mapping \
        -c ./*.c

    clang \
        -fprofile-instr-generate -fcoverage-mapping -Wdocumentation \
        -o app.exe ./*.o \
        -lm
fi
