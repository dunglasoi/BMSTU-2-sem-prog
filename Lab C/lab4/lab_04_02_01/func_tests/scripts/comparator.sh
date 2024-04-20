#!/bin/bash

# task3
#
# ошибка: неправильное количество параметров
[[ $# -lt 2 || $# -gt 3 ]] && { echo "comparator: Wrong parameter count"; exit 2; }
# filename
file1=$1
file2=$2
# регулярное выражение
regex="^[+-]?[0-9]+$"
# конец файла
eof1=0
eof2=0
# цикл для работы с 2 файлами одновременно
while true; do
	# если два файла достигают конца
	[[ $eof1 -eq 1 && $eof2 -eq 1 ]] && break
	# number
	num1=""
	num2=""
	# прочитать файл по байтам, найти следующее число в файле1
	while true; do
		read -r -N 1 <&3 || eof1=1
		# проверяем, достигнут ли конец файла
		if [[ $eof1 -eq 1 ]]; then
			break
		else
		# проверяем, соответствует ли $num2 регулярному выражению $regex
			if [[ "$num1" =~ $regex ]]; then
				break
			else
				num1=""
			fi
		fi
	done
	# прочитать файл по байтам, найти следующее число в файле2
	while true; do
		read -r -N 1 <&4 || eof2=1
		# проверяем, достигнут ли конец файла
		if [[ $eof2 -eq 1 ]]; then
			break
		else
		# проверяем, соответствует ли $num2 регулярному выражению $regex
			if [[ "$num2" =~ $regex ]]; then
				break
			else
				num2=""
			fi
		fi
	done
	# сравнить 2 числа
	if [[ "$num1" =~ $regex && "$num2" =~ $regex ]]; then
		if [[ "$3" = "-v" ]]; then
  			comparison="Comparing $num1 & $num2"
  			echo "$comparison"
		else
  			comparison=""
		fi
		if [[ "$num1" != "$num2" ]]; then
			if [[ "$3" = "-v" ]]; then
				echo "file: $file1 != file: $file2"
			fi
			exit 1
		fi
	fi
	# передать сюда файловый дескриптор
done 3<"$file1" 4<"$file2"
# файлы равны
if [[ "$3" = "-v" ]]; then 
	if [[ "$file1" != "$file2" ]]; then
    	echo "file: $file1 != file: $file2"
    	exit 1
  	fi
else
	if [[ "$file1" != "$file2" ]]; then
    	exit 1
  	fi
fi
exit 0