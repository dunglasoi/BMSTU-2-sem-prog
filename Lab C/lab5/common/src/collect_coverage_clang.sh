#!/bin/bash
#
# Хуинь Вьет Хынг ИУ7-22Б, ИУ7И-27Б
#
# Collect code coverage information with clang
#

for f in ./func_tests/data/*_in.txt; do
    ./app.exe <"$f" >/dev/null 2>&1
done

llvm-profdata merge -sparse default.profraw -o default.profdata
# llvm-cov show ./app.exe -instr-profile=default.profdata
llvm-cov report ./app.exe -instr-profile=default.profdata
