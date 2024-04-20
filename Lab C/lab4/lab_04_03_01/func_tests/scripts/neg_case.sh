#!/bin/bash

input_file="$1"

# Проверяем, что файл существует
if [ ! -f "$1" ]; then
    echo "Error: file '$1' not found" >&2
    exit 1
fi

# Запускаем программу app.exe с вводом из файла и выводом в /dev/null
if ! ../../app.exe < "$1" > /dev/null 2>&1; then
  exit 0
else
  exit 1
fi
exit "$input_file"