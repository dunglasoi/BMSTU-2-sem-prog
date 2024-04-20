#!/usr/bin/env bash

COMPARATOR="func_tests/scripts/comparator.sh"
APP="./app.exe"

TEMP=result.temp

RUN_COMMAND="$APP"

if [ "$#" -lt 2 ]; then
    >&2 echo "Usage: pos_case.sh file_stream_in file_stream_out [file_app_args]"
    exit 1
fi

file_in="$1"
file_out="$2"
file_args="$3"

mode=

if [ -n "$file_args" ]; then
    RUN_COMMAND="$RUN_COMMAND $(cat "$file_args")"
fi

rc=1

cp "$file_in" /tmp/in.temp
cp "$file_out" /tmp/out.temp

pushd ../../ > /dev/null || exit 1

cp ./func_tests/data/test.bin /tmp/test.bin

if [ -n "$USE_VALGRIND" ]; then
    valgrind --quiet --leak-check=full "$RUN_COMMAND" < /tmp/in.temp > "$TEMP" 2> err.temp
    valgrind_rc=$?
    if [ "$valgrind_rc" -eq 0 ] && $COMPARATOR "$TEMP" /tmp/out.temp ; then
        rc=0
    fi

    if [ -n "$(cat err.temp)" ]; then
        rc=$((rc + 2))
    fi
else
    if $RUN_COMMAND < /tmp/in.temp > $TEMP && $COMPARATOR "$TEMP" /tmp/out.temp; then
        if [ "$mode" == "st" ]; then
            rc=$(diff "/tmp/out.bin" "func_tests/data/test01.bin")
        elif [ "$mode" == "ab" ]; then
            rc=$(diff "func_tests/data/test.bin" "func_tests/data/test02.bin")
        fi
        rc=0
    fi
fi

cp /tmp/test.bin ./func_tests/data/test.bin

popd > /dev/null || exit 1

exit "$rc"

