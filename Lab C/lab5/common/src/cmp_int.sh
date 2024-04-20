#!/bin/bash
#
# Хуинь Вьет Хынг ИУ7-22Б, ИУ7И-27Б
#
# task1
# Compare two files by integer
#

usage="usage: comparator file1 file2 [-v]"

# error: wrong parameter count
if [[ $# -lt 2 || $# -gt 3 ]]; then
    echo "comparator: Wrong parameter count"
    echo "$usage"
    exit 2
fi

# error: wrong option
if [[ $# -eq 3 && $3 != "" && $3 != "-v" ]]; then
    echo "comparator: Wrong option"
    echo "$usage"
    exit 3
fi

# filename
file1=$1
file2=$2

# regex
regex="^[+-]?[0-9]+$"
space="[[:space:]]"

# end of file
eof1=0
eof2=0

# loop for working with 2 file simultaneuosly
while true; do
    # if two file reach end
    if [[ $eof1 -eq 1 && $eof2 -eq 1 ]]; then
        break
    fi
    # number
    num1=""
    num2=""
    # read file by byte, find next number in file1
    while true; do
        read -r -N 1 c <&3 || eof1=1
        # has eof
        if [[ $eof1 -eq 1 ]]; then
            break
        fi
        # has space
        if [[ "$c" =~ $space ]]; then
            if [[ "$num1" =~ $regex ]]; then
                break
            fi
            num1=""
        else
            # forming number
            num1=$num1$c
        fi
    done
    # read file by byte, find next number in file2
    while true; do
        read -r -N 1 c <&4 || eof2=1
        # has eof
        if [[ $eof2 -eq 1 ]]; then
            break
        fi
        # has space
        if [[ "$c" =~ $space ]]; then
            if [[ "$num2" =~ $regex ]]; then
                break
            fi
            num2=""
        else
            # forming number
            num2=$num2$c
        fi
    done

    # compare 2 numbers
    if [[ "$num1" =~ $regex && "$num2" =~ $regex ]]; then
        if [[ "$3" = "-v" ]]; then
            echo "Comparing $num1 & $num2"
        fi

        if [[ "$num1" != "$num2" ]]; then
            if [[ "$3" = "-v" ]]; then
                echo "file: $file1 != file: $file2"
            fi
            exit 1
        fi
    elif [[ "$num1" =~ $regex ]]; then
        if [[ "$3" = "-v" ]]; then
            echo "file1 has more number then file2"
            echo "file: $file1 != file: $file2"
        fi
        exit 4
    elif [[ "$num2" =~ $regex ]]; then
        if [[ "$3" = "-v" ]]; then
            echo "file2 has more number then file1"
            echo "file: $file1 != file: $file2"
        fi
        exit 5
    fi

    # pass file descriptor here
done 3<"$file1" 4<"$file2"

# files are equal
if [[ "$3" = "-v" ]]; then
    echo "file: $file1 == file: $file2"
fi
exit 0
