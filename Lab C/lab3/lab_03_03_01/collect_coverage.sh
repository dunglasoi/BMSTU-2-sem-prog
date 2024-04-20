#!/bin/bash

for file in ./func_tests/data/*_in.txt; do
    base=$(basename -s _in.txt "$file")

    ./app.exe <"$file" >"$base"_out.txt 2>/dev/null

    if [ -s "$base"_out.txt ]; then
        echo "Test $base: PASSED"
    else
        echo "Test $base: FAILED"
    fi
done

gcov ./*.c
