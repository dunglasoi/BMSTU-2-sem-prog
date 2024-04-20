#!/bin/bash

if [[ $# -lt 2 || $# -gt 3 ]]; then
  echo "comparator: Wrong parameter count"
  exit 2
fi

file1=$1
file2=$2

regex="^[+-]?[0-9]*\.[0-9]+$"

tempfile=$(mktemp)

../../app.exe < "$file1" > "$tempfile"

if ./comparator.sh "$tempfile" "$file2"; then 
  rm "$tempfile" && exit 0 || rm "$tempfile" && exit 1
fi

rm "$tempfile"