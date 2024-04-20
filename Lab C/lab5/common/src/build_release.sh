#!/bin/bash
#
# Хуинь Вьет Хынг ИУ7-22Б, ИУ7И-27Б
#
# Build program for release
#

gcc \
    -std=c99 -Wall -Werror -Wextra -Wpedantic \
    -Wfloat-equal -Wfloat-conversion \
    -Wvla \
    -D NDEBUG \
    -c ./*.c

gcc \
    -o app.exe ./*.o \
    -lm
