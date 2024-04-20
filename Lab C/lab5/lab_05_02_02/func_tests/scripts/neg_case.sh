#!/usr/bin/env bash

RUN_COMMAND="./app.exe"

if [ "$#" -lt 2 ]; then
    >&2 echo "Usage: pos_case.sh file_stream_in [file_app_args]"
    exit 1
fi

file_in="$1"
file_args="$2"

if [ -n "$file_args" ]; then
    RUN_COMMAND="$RUN_COMMAND $(cat "$file_args")"
fi

rc=0

cp "$file_in" /tmp/in.temp

pushd ../../ > /dev/null || exit 1

if [ -n "$USE_VALGRIND" ]; then
    valgrind --quiet --leak-check=full "$RUN_COMMAND" < /tmp/in.temp 2>&1 /dev/null
    valgrind_rc=$?
    if [ "$valgrind_rc" -eq 0 ]; then
        rc=1
    fi

    if [ -n "$(cat err.temp)" ]; then
        rc=$((rc + 2))
    fi
else
    if $RUN_COMMAND < /tmp/in.temp 2>&1 /dev/null ; then
        rc=1
    fi
fi

popd > /dev/null || exit 1

exit "$rc"

