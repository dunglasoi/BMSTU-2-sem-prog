#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "my_string.h"

int get_line(char *buf, size_t buf_size)
{
    assert(buf != NULL);

    if (fgets(buf, buf_size, stdin) == NULL)
    {
        return ERR_IO;
    }

    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n')
    {
        buf[len - 1] = '\0';
        return OK;
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Использовать оставшуюся часть входной строки
    }

    if (len == buf_size - 1)
    {
        return ERR_STR_LEN;
    }
    else
    {
        return OK;
    }
}

void get_next_word(char *str, char **pbeg, char **pend)
{
    assert(pbeg != NULL);
    assert(pend != NULL);
    *pbeg = *pend = NULL;

    // Найдите начало следующего слова
    while (*str && strchr(DELIMS, *str))
        str++;
    if (!*str)
        return;
    *pbeg = str;

    // Найдите конец следующего слова
    while (*str && !strchr(DELIMS, *str))
        str++;
    *pend = str;
}

int copy_word(const char *pbeg, const char *pend, char *word, size_t word_size)
{
    assert(pbeg != NULL);
    assert(pend != NULL);
    assert(word != NULL);
    size_t i = 0;
    while (pbeg < pend && i < word_size - 1)
    {
        word[i++] = *pbeg++;
    }
    word[i] = '\0';

    if (pbeg < pend)
    {
        return ERR_WORD_LEN;
    }

    return OK;
}

int has_word(const char *pbeg, const char *pend, char words[][WORD_LEN], size_t words_n)
{
    assert(pbeg != NULL);
    assert(pend != NULL);
    assert(words != NULL);
    for (size_t i = 0; i < words_n; i++)
    {
        if (!strncmp(pbeg, words[i], pend - pbeg))
            return 1;
    }
    return 0;
}

int split_string_into_words(char *str, char words[][WORD_LEN], size_t *words_n)
{
    assert(words != NULL);
    assert(words_n != NULL);
    char *pbeg = str, *pend = str;
    size_t n = 0;
    int rc = OK;

    while (*pend)
    {
        while (*pbeg && strchr(DELIMS, *pbeg))
            pbeg++;

        if (!*pbeg)
            break;

        pend = pbeg;
        while (*pend && !strchr(DELIMS, *pend))
            pend++;

        if (!has_word(pbeg, pend, words, n))
        {
            if (n < N_MAX)
            {
                rc = copy_word(pbeg, pend, words[n], sizeof(words[n]));
                if (rc == OK)
                    n++;
            }
            else
            {
                rc = ERR_RANGE;
                break;
            }
        }
        pbeg = pend;
    }

    *words_n = n;
    return rc;
}

void sort_words(char words[][WORD_LEN], size_t words_n)
{
    assert(words != NULL);

    if (words_n < 2)
        return;

    for (size_t i = 0; i < words_n - 1; i++)
    {
        for (size_t j = i + 1; j < words_n; j++)
        {
            if (strncmp(words[i], words[j], WORD_LEN) > 0)
            {
                char tmp[WORD_LEN];
                strncpy(tmp, words[i], WORD_LEN);
                strncpy(words[i], words[j], WORD_LEN);
                strncpy(words[j], tmp, WORD_LEN);
            }
        }
    }
}

int join_words_into_string(char words[][WORD_LEN], size_t words_n, char *buf, size_t buf_size)
{
    assert(words != NULL);
    assert(buf != NULL);
    if (words_n == 0)
        return ERR_RANGE;

    // Вычислить длину полученной строки
    size_t need = 0;
    for (size_t i = 0; i < words_n; i++)
        need += strlen(words[i]);

    // Проверить, может ли результирующая строка поместиться в буфер

    if (need + words_n - 1 >= buf_size)
        return ERR_STR_LEN;

    // Соедините слова в строку
    size_t pos = 0;
    for (size_t i = 0; i < words_n; i++)
    {
        size_t len = strlen(words[i]);
        memcpy(buf + pos, words[i], len);
        pos += len;
        if (i < words_n - 1)
        {
            buf[pos++] = ' ';
        }
    }
    buf[pos] = '\0';

    return OK;
}
