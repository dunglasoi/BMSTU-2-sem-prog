#!/bin/bash

# Check number of parameters
if [[ $# -lt 2 || $# -gt 3 ]]; then
  echo "comparator: Wrong parameter count"
  exit 2
fi

# Assign filenames to variables
file1=$1
file2=$2

# Define regular expression to match floating point numbers
regex="^[+-]?[0-9]*\.[0-9]+$"

# Initialize end of file flags
eof1=0
eof2=0

# Loop through both files simultaneously
for (( i=0; eof1!=1 || eof2!=1; i++ )); do

  # Read one byte at a time from file1 until a floating point number is found
  num1=""
  while read -n 1 -r -u 3 byte; do
    if [[ "$byte" =~ $regex ]]; then
      num1="$num1$byte"
    elif [[ "$num1" != "" ]]; then
      break
    fi
  done

  # Read one byte at a time from file2 until a floating point number is found
  num2=""
  while read -n 1 -r -u 4 byte; do
    if [[ "$byte" =~ $regex ]]; then
      num2="$num2$byte"
    elif [[ "$num2" != "" ]]; then
      break
    fi
  done

  # Compare the two numbers
  if [[ "$num1" =~ $regex && "$num2" =~ $regex ]]; then
    if [[ "$3" = "-v" ]]; then
      comparison="Comparing $num1 & $num2"
      echo "$comparison"
    fi
    if [[ "$num1" != "$num2" ]]; then
      if [[ "$3" = "-v" ]]; then
        echo "file: $file1 != file: $file2"
      fi
      exit 1
    fi
  fi

  # Set end of file flags
  if ! read -n 1 -r -u 3 && [[ ${PIPESTATUS[0]} -ne 0 ]]; then
    eof1=1
  fi
  if ! read -n 1 -r -u 4 && [[ ${PIPESTATUS[0]} -ne 0 ]]; then
    eof2=1
  fi
done 3< "$file1" 4< "$file2"

# Check if files are equal
if [[ "$file1" != "$file2" ]]; then
  if [[ "$3" = "-v" ]]; then
    echo "file: $file1 != file: $file2"
  fi
  exit 1
fi

exit 0