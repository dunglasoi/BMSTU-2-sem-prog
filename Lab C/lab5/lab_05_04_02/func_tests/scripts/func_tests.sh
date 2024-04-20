#!/usr/bin/env bash

DIR="../data"
POS_SCRIPT="./pos_case.sh"
NEG_SCRIPT="./neg_case.sh"

error_count=0
memory_error_count=0

process_test_result () {
    local file=$1
    local rc=$2
    if [ "$rc" -eq 1 ]; then
        >&2 echo "Test $file result failed"
        error_count=$((error_count + 1))
    elif [ "$rc" -eq 2 ]; then
        >&2 echo "Test $file memory failed"
        memory_error_count=$((memory_error_count + 1))
    elif [ "$rc" -eq 3 ]; then
        >&2 echo "Test $file memory and result failed"
        memory_error_count=$((memory_error_count + 1))
        error_count=$((error_count + 1))
    fi
}

pos_ins=$(find "$DIR" -name "pos_*_in.txt")
for pos_in in $pos_ins; do
    pos_out=${pos_in/_in/_out}
    pos_arg=${pos_in/_in/_args}
    if [ ! -f "$pos_arg" ]; then
        pos_arg=""
    fi

    if [ ! -f "$pos_out" ]; then
        >&2 echo "$pos_in is present, but there is no $pos_out"
    else
        $POS_SCRIPT "$pos_in" "$pos_out" "$pos_arg"
        rc=$?
        process_test_result "$pos_in" "$rc"
    fi
done

neg_ins=$(find "$DIR" -name "neg_*_in.txt")
for neg_in in $neg_ins; do
    neg_arg=${neg_in/_in/_arg}
    if [ ! -f "$neg_arg" ]; then
        neg_arg=""
    fi

    $NEG_SCRIPT "$neg_in" "$neg_arg"
    rc=$?
    process_test_result "$neg_in" "$rc"
done

if [ "$error_count" -eq 0 ] && [ "$memory_error_count" -eq 0 ]; then
    echo "All tests passed"
else
    if [ -n "$USE_VALGRIND" ]; then
        >&2 echo -n "Memory failed: $memory_error_count; "
    fi
    >&2 echo "Tests failed: $error_count"
fi

exit $((error_count + memory_error_count))

