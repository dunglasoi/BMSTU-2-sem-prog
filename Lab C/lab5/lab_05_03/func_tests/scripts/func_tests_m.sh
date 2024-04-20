#!/bin/bash

# Functional test program
#

file_exe=./app.exe
filename=/tmp/data.bin

# Тест создание
echo "Тест создание"
$file_exe c 20 $filename
$file_exe p $filename

# Ошибка в аргументе
echo ""
echo "Ошибка в количестве аргументов"
$file_exe
$file_exe c
$file_exe c 1
$file_exe c 1 2 3
$file_exe p
$file_exe p 1 2
$file_exe s
$file_exe s 1 2

# Ошибка в number
echo ""
echo "Ошибка в number (app.exe c number file)"
$file_exe c -1 $filename
$file_exe c 23g $filename
