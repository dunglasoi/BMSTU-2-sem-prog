#!/bin/bash

file=$(mktemp)

input_file="$1"
output_file="$file"
../../app.exe < "$input_file" > "$output_file"

if ./comparator.sh "$file" "$2"; then 
  rm "$file" && exit 0 || rm "$file" && exit 1
fi
