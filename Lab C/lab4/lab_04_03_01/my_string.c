#include <stdio.h>
#include <string.h>
#include "my_string.h"
#include <assert.h>
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

char *delete_duplicate_char(char *s)
{
    assert(s != NULL);
    char *p = s;

    while (*p)
    {
        if (strchr(s, *p) != p)
            memmove(p, p + 1, strlen(p));
        else
            p++;
    }

    return s;
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

        pbeg = pend;
    }

    *words_n = n;
    return rc;
}

void process_words(char words[][WORD_LEN], size_t *words_n)
{
    assert(words != NULL);
    assert(words_n != NULL);

    if (*words_n == 0)
    {
        return;
    }

    size_t last_index = *words_n - 1;
    char *last_word = words[last_index];

    size_t write_index = 0;

    for (size_t i = 0; i < last_index; i++)
    {
        if (strncmp(words[i], last_word, WORD_LEN) == 0)
        {
            continue;
        }
        delete_duplicate_char(words[i]);
        if (i != write_index)
        {
            strcpy(words[write_index], words[i]);
        }
        write_index++;
    }

    *words_n = write_index;
}

int form_string_reverse(char words[][WORD_LEN], size_t words_n, char *buf, size_t buf_size)
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

    // Соедините слова в строку в обратном порядке
    size_t pos = 0;
    for (size_t i = words_n; i > 0; i--)
    {
        size_t len = strlen(words[i - 1]);
        memcpy(buf + pos, words[i - 1], len);
        pos += len;
        if (i > 1)
        {
            buf[pos++] = ' ';
        }
    }
    buf[pos] = '\0';

    return OK;
}
