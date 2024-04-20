#!/bin/bash
#
# Хуинь Вьет Хынг ИУ7-22Б, ИУ7И-27Б
#
# task2
# Compare two files after 'string:'
#

usage="usage: comparator file1 file2 str [-v]"

# error: wrong parameter count
if [[ $# -lt 3 || $# -gt 4 ]]; then
    echo "comparator: Wrong parameter count"
    echo "$usage"
    exit 2
fi

# error: wrong option
if [[ $# -eq 4 && $4 != "" && $4 != "-v" ]]; then
    echo "comparator: Wrong option"
    echo "$usage"
    exit 3
fi

# filename
file1=$1
file2=$2

# regex
regex=$3
len=${#regex}

# end of file
eof1=0
eof2=0

# loop for working with 2 file simultaneuosly
while true; do
    # read file by byte, find 'string:' in file1
    str=""
    byte=0
    while true; do
        read -r -N 1 c <&3 || eof1=1
        byte=$((byte + 1))
        # found 'string:'
        if [[ "$str" == "$regex" ]]; then
            if [[ "$4" = "-v" ]]; then
                echo "file1: found $regex at $byte byte"
            fi
            break
        else
            # forming string
            str=$str$c
            # max length > $len, cut it
            if [[ ${#str} -gt $len ]]; then
                str=${str:1:$len}
            fi
        fi
        # has eof
        if [[ $eof1 -eq 1 ]]; then
            break
        fi
    done
    # read file by byte, find 'string:' in file2
    str=""
    byte=0
    while true; do
        read -r -N 1 c <&4 || eof2=1
        byte=$((byte + 1))
        # found 'string:'
        if [[ "$str" == "$regex" ]]; then
            if [[ "$4" = "-v" ]]; then
                echo "file2: found $regex at $byte byte"
            fi
            break
        else
            # forming string
            str=$str$c
            # max length > $len, cut it
            if [[ ${#str} -gt $len ]]; then
                str=${str:1:$len}
            fi
        fi
        # has eof
        if [[ $eof2 -eq 1 ]]; then
            break
        fi
    done

    # found start position, now just compare
    while true; do
        # if two file reach end
        if [[ $eof1 -eq 1 || $eof2 -eq 1 ]]; then
            # eof same time, equal
            if [[ $eof1 -eq 1 && $eof2 -eq 1 ]]; then
                if [[ "$4" = "-v" ]]; then
                    echo "file: $file1 == file: $file2"
                fi
                exit 0
            # otherwise, not equal
            else
                if [[ "$4" = "-v" ]]; then
                    echo "file: $file1 != file: $file2"
                fi
                exit 1
            fi
        fi
        # read
        read -r -N 1 c1 <&3 || eof1=1
        read -r -N 1 c2 <&4 || eof2=1
        # if char in file1 != char in file2
        if [[ "$c1" != "$c2" ]]; then
            if [[ "$4" = "-v" ]]; then
                echo "file: $file1 != file: $file2"
            fi
            exit 1
        fi
    done

    # pass file descriptor here
done 3<"$file1" 4<"$file2"
