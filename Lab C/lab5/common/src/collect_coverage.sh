#!/bin/bash
#
# Хуинь Вьет Хынг ИУ7-22Б, ИУ7И-27Б
#
# Collect code coverage information
#

for f in ./func_tests/data/*_in.txt; do
    ./app.exe <"$f" >/dev/null 2>&1
done

gcov ./*.c
