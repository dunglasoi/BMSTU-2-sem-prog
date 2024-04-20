#!/usr/bin/env bash

OUT=app.exe
if [ -z "$CC" ]; then
  CC=gcc
fi

$CC -pedantic -Werror -Wextra -Wall -Wfloat-equal -Wfloat-conversion -Wvla -std=c99 -O0 -g -c "base.c"
$CC -pedantic -Werror -Wextra -Wall -Wfloat-equal -Wfloat-conversion -Wvla -std=c99 -O0 -g -c "main.c"
$CC -o "$OUT" -lm main.o base.o
