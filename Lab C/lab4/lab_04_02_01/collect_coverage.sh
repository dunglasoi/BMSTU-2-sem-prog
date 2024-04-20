#!/bin/bash
find ./func_tests/data -name '*_in.txt' | while read f; do
    ./app.exe <"$f" >/dev/null 2>&1
done

gcov ./*.c

