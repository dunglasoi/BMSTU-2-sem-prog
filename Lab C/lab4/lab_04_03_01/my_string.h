#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <stddef.h>

#define STR_LEN (256 + 1) // Длина строки
#define WORD_LEN (16 + 1) // Длина слово
#define DELIMS " ,;:-.!?" // Знаки пунктуация
#define N_MAX ((STR_LEN - 1) / 2)  
       
#define OK 0           /** Все хорошо */
#define ERR_IO 1       /** ошибка: Ввод/Вывод */
#define ERR_RANGE 2    /** ошибка: Значение вне допустимого диапазона */
#define ERR_STR_LEN 3  /** ошибка: Длина строки */
#define ERR_WORD_LEN 4 /** ошибка: Длина слово */
int get_line(char *buf, size_t buf_size);

int split_string_into_words(char *str, char words[][WORD_LEN], size_t *words_n);

void process_words(char words[][WORD_LEN], size_t *words_n);
int form_string_reverse(char words[][WORD_LEN], size_t words_n, char *buf, size_t buf_size);
#endif // _MY_STRING_H_
