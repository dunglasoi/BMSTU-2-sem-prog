#!/usr/bin/env bash

find . -name "*.temp" -exec rm {} \;
rm -rf ./*.dSYM 2> /dev/null # MacOS
find . -name "*.o" -exec rm {} \;
find . -name "*.exe" -exec rm {} \;
find . -name "vgcore*" -exec rm {} \; # valgrind
