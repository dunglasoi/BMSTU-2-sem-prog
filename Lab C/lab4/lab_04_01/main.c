#include <stdio.h>
#include <string.h>
#include "my_string.h"

#define ASCII_TOTAL 128 /** Количество ascii символов*/
#define N_CMP 4         /** Количество сравнении */

// res1, res2 оставил для отладки

void cmp_strpbrk(char *test_str[WORD_LEN], char *test_charset[WORD_LEN])
{
    int n_fail = 0;
    char *res1, *res2;

    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < N_CMP; i++)
        {
            if ((res1 = strpbrk(test_str[i], test_charset[j])) != (res2 = my_strpbrk(test_str[i], test_charset[j])))
                n_fail++;
        }
    }

    printf("cmp_strpbrk: failed %d times\n", n_fail);
}

void cmp_strspn(char *test_str[WORD_LEN], char *test_charset[WORD_LEN])
{
    int n_fail = 0;

    for (int i = 0; i < N_CMP; i++)
    {
        size_t res1 = strspn(test_str[i], test_charset[0]);
        size_t res2 = my_strspn(test_str[i], test_charset[0]);
        if (res1 != res2)
        {
            n_fail++;
        }

        res1 = strspn(test_str[i], test_charset[1]);
        res2 = my_strspn(test_str[i], test_charset[1]);
        if (res1 != res2)
        {
            n_fail++;
        }
    }

    printf("cmp_strspn: failed %d times\n", n_fail);
}

void cmp_strcspn(char *test_str[WORD_LEN], char *test_charset[WORD_LEN])
{
    int n_fail = 0;
    size_t res1, res2;

    for (int i = 0; i < N_CMP; i++)
    {
        res1 = strcspn(test_str[i], test_charset[0]);
        res2 = my_strcspn(test_str[i], test_charset[0]);
        if (res1 != res2)
            n_fail++;

        res1 = strcspn(test_str[i], test_charset[1]);
        res2 = my_strcspn(test_str[i], test_charset[1]);
        if (res1 != res2)
            n_fail++;
    }

    printf("cmp_strcspn: failed %d times\n", n_fail);
}

void cmp_strchr(char *test_str[WORD_LEN], char *test_charset[WORD_LEN])
{
    int n_fail = 0;

    for (int i = 0; i < N_CMP; i++)
    {
        char *res1 = strchr(test_str[i], test_charset[0][0]);
        char *res2 = my_strchr(test_str[i], test_charset[0][0]);
        if (res1 != res2)
            n_fail++;

        res1 = strchr(test_str[i], test_charset[1][0]);
        res2 = my_strchr(test_str[i], test_charset[1][0]);
        if (res1 != res2)
            n_fail++;
    }

    printf("cmp_strchr: failed %d times\n", n_fail);
}

void cmp_strrchr(char *test_str[WORD_LEN], char *test_charset[WORD_LEN])
{
    int n_fail = 0;
    char *res1, *res2;

    for (int i = 0; i < N_CMP; i++)
    {
        char ch1 = test_charset[0][0];
        char ch2 = test_charset[1][0];
        res1 = strrchr(test_str[i], ch1);
        res2 = my_strrchr(test_str[i], ch1);
        if (res1 != res2)
            n_fail++;
        res1 = strrchr(test_str[i], ch2);
        res2 = my_strrchr(test_str[i], ch2);
        if (res1 != res2)
            n_fail++;
    }

    printf("cmp_strrchr: failed %d times\n", n_fail);
}

int main(void)
{
    char *test_str[WORD_LEN] = { "Hello, world!", "", "howareyou\0and\0and", "taolaai" };
    char *test_charset[WORD_LEN] = { "ailatao", "\0" };
    cmp_strpbrk(test_str, test_charset);
    cmp_strspn(test_str, test_charset);
    cmp_strcspn(test_str, test_charset);
    cmp_strchr(test_str, test_charset);
    cmp_strrchr(test_str, test_charset);

    return 0;
}
