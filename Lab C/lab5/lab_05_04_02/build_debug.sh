#!/usr/bin/env bash

OUT=app.exe
if [ -z "$CC" ]; then
  CC=gcc
fi

$CC -pedantic -Werror -Wextra -Wall -Wfloat-equal -Wfloat-conversion -Wvla -std=c99 -O0 -g -c "file_io.c"
$CC -pedantic -Werror -Wextra -Wall -Wfloat-equal -Wfloat-conversion -Wvla -std=c99 -O0 -g -c "main.c"
$CC -pedantic -Werror -Wextra -Wall -Wfloat-equal -Wfloat-conversion -Wvla -std=c99 -O0 -g -c "mode_insert.c"
$CC -pedantic -Werror -Wextra -Wall -Wfloat-equal -Wfloat-conversion -Wvla -std=c99 -O0 -g -c "mode_print.c"
$CC -pedantic -Werror -Wextra -Wall -Wfloat-equal -Wfloat-conversion -Wvla -std=c99 -O0 -g -c "mode_sort.c"
$CC -pedantic -Werror -Wextra -Wall -Wfloat-equal -Wfloat-conversion -Wvla -std=c99 -O0 -g -c "products.c"
$CC -pedantic -Werror -Wextra -Wall -Wfloat-equal -Wfloat-conversion -Wvla -std=c99 -O0 -g -c "string_util.c"
$CC -o "$OUT" -lm file_io.o main.o mode_insert.o mode_print.o mode_sort.o products.o string_util.o
