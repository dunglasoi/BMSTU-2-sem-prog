#!/bin/bash 
if gcc -c -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion main.c --coverage -O0; then 
    echo "Compilation successful"
else
    echo "Compilation failed. Exiting..." 
    exit 1 
fi 
if gcc main.o -o app.exe -lm --coverage; then 
    echo "Linking successful"
else
    echo "Linking failed. Exiting..." 
    exit 1 
fi 
cd ./func_tests/scripts || { echo "Directory not found. Exiting..."; exit 1; }
./func_tests.sh > ../func_tests_output.txt || { echo "Functional tests failed. Exiting..."; exit 1; }
cat func_tests_output.txt
cd ../../

# Generate gcov report
gcov main.c || { echo "gcov failed. Exiting..."; exit 1; }