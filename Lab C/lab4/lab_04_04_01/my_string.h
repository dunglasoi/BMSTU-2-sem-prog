#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <stddef.h>

#define STR_LEN (256 + 1) // Длина строки
#define WORD_LEN (16 + 1) // Длина слово
#define N_MAX 10          // Количество слово в массиве слов


#define OK 0           /** Все хорошо */
#define ERR_IO 1       /** ошибка: Ввод/Вывод */
#define ERR_RANGE 2    /** ошибка: Значение вне допустимого диапазона */
#define ERR_STR_LEN 3  /** ошибка: Длина строки */
#define ERR_WORD_LEN 4 /** ошибка: Длина слово */
#define ERR_REGEX 5    /** ошибка: Регулярное выражение */


int get_line(char *buf, size_t buf_size);

int is_float(const char s[]);

#endif // _MY_STRING_H_
