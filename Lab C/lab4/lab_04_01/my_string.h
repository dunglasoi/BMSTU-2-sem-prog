#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <stddef.h>

#define STR_LEN (256 + 1) // Длина строки
#define WORD_LEN (16 + 1) // Длина слово
#define DELIMS " ,;:-.!?" // Знаки пунктуация

// Ищет первое совпадение в строке `s` с любым символом из строки `charset`
char *my_strpbrk(const char *s, const char *charset);

// Ищет первое не совпадение в строке `s` с любым символом из строки `charset`
size_t my_strspn(const char *s, const char *charset);

// Ищет первое совпадение в строке `s` с любым символом из строки `charset`
size_t my_strcspn(const char *s, const char *charset);

// Найти символ `c` в строке `s`

char *my_strchr(const char *s, int c);

// Найти символ `c` в строке `s` с конца

char *my_strrchr(const char *s, int c);

#endif // _MY_STRING_H_
