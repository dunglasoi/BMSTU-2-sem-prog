#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
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

int is_float(const char s[])
{
    // Пропустить начальный пробел
    int i = 0;
    while (isspace(s[i]))
        i++;

    // Необязательный знак
    if (s[i] == '+' || s[i] == '-')
        i++;

    // Хотя бы одна цифра перед точкой
    if (isdigit(s[i]))
        i++;
    else if (s[i] == '.' && isdigit(s[i + 1]))
    {
    }
    else if (!isdigit(s[i]))
        return 0;

    while (isdigit(s[i]))
        i++;

    // Optional dot
    if (s[i] == '.')
        i++;

    // [0-9]*
    while (isdigit(s[i]))
        i++;

    // Optional exponent
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        // экспонент без цифр после
        if (s[i] == '\0')
            return 0;
    }

    // [+-]?
    if ((s[i] == '+' || s[i] == '-') && (s[i - 1] == 'e' || s[i - 1] == 'E'))
    {
        i++;
        // экспонент без цифр после
        if (s[i] == '\0')
            return 0;
    }

    // [0-9]*
    while (isdigit(s[i]))
        i++;

    // Пропустить пробелы в конце
    while (isspace(s[i]))
        i++;

    // Проверяем, не конец ли строки
    if (s[i] == '\0')
        return 1;

    return 0;
}
// int has_float(char *s)
// {

//     int i = 0;

//     // Skip leading white space
//     while (isspace(s[i]))
//         i++;

//     // Optional sign
//     if (s[i] == '+' || s[i] == '-')
//         i++;

//     // At least one digit before dot
//     if (!isdigit(s[i]))
//         return 0;

//     while (isdigit(s[i]))
//         i++;

//     // Optional dot
//     if (s[i] == '.')
//     {
//         i++;

//         // Optional digits after dot
//         while (isdigit(s[i]))
//             i++;

//         // Check for special case of ".0"
//         if (s[i - 1] == '0' && !isdigit(s[i]))
//             return 0;
//     }

//     // Optional exponent
//     if (s[i] == 'e' || s[i] == 'E')
//     {
//         i++;

//         // Optional sign
//         if (s[i] == '+' || s[i] == '-')
//             i++;

//         // At least one digit after exponent
//         if (!isdigit(s[i]))
//             return 0;

//         while (isdigit(s[i]))
//             i++;
//     }

//     // Skip trailing white space
//     while (isspace(s[i]))
//         i++;

//     return s[i] == '\0';
// }