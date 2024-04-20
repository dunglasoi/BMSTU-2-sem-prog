#include <stdio.h>
#include "my_string.h"
void print_error(int err);
int main(void)
{
    int ret = OK;
    size_t n_word = 0;
    char strings[STR_LEN];
    char new_str[STR_LEN];
    char words[N_MAX][WORD_LEN];

    ret = get_line(strings, STR_LEN);
    if (ret)
    {
        print_error(ret);
        return ret;
    }

    ret = split_string_into_words(strings, words, &n_word);
    if (ret)
    {
        print_error(ret);
        return ret;
    }

    process_words(words, &n_word);
    ret = form_string_reverse(words, n_word, new_str, STR_LEN);
    if (ret)
    {
        print_error(ret);
        return ret;
    }

    printf("Result: %s\n", new_str);

    return ret;
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