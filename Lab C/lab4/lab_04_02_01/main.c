#include <stdio.h>
#include "my_string.h"

void print_error(int err);

int main(void)
{
    int ret_code = OK;
    size_t n_word = 0;
    char strings[STR_LEN];
    char words[N_MAX][WORD_LEN];

    ret_code = get_line(strings, STR_LEN);
    if (ret_code != OK)
    {
        print_error(ret_code);
        return ret_code;
    }

    ret_code = split_string_into_words(strings, words, &n_word);
    if (ret_code != OK)
    {
        print_error(ret_code);
        return ret_code;
    }

    sort_words(words, n_word);
    ret_code = join_words_into_string(words, n_word, strings, STR_LEN);
    if (ret_code != OK)
    {
        print_error(ret_code);
        return ret_code;
    }

    printf("Result: %s\n", strings);

    return OK;
}

void print_error(int err)
{
    switch (err)
    {
        case ERR_IO:
            printf("Error: Ввод/Вывод\n");
            break;
        case ERR_RANGE:
            printf("Error: Значение вне допустимого диапазона\n");
            break;
        case ERR_STR_LEN:
            printf("Error: Длина строки\n");
            break;
        case ERR_WORD_LEN:
            printf("Error: Длина слово\n");
            break;
        case OK:
            break;
        default:
            printf("Error: Неизвестный код!\n");
            break;
    }
}
