#!/bin/bash

find . -maxdepth 1 -type f -name '.exe' -o -name '.o' -o -name '.out' -o -name '.gcno' -o -name '.gcda' -o -name '.gcov' -delete
