#include "my_string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Аналог функции strpbrk
char *my_strpbrk(const char *str1, const char *str2)
{
    const char *p;
    const char *q;

    for (p = str1; *p != '\0'; p++)
    {
        for (q = str2; *q != '\0'; q++)
        {
            if (*p == *q)
            {
                return (char *)p;
            }
        }
    }

    return NULL;
}

// Аналог функции strspn
size_t my_strspn(const char *str1, const char *str2)
{
    const char *p;
    const char *q;
    size_t count = 0;

    for (p = str1; *p != '\0'; p++)
    {
        for (q = str2; *q != '\0'; q++)
        {
            if (*p == *q)
            {
                count++;
                break;
            }
        }

        if (*q == '\0')
        {
            return count;
        }
    }

    return count;
}

// Аналог функции strcspn
size_t my_strcspn(const char *str1, const char *str2)
{
    const char *p;
    const char *q;
    size_t count = 0;

    for (p = str1; *p != '\0'; p++)
    {
        for (q = str2; *q != '\0'; q++)
        {
            if (*p == *q)
            {
                return count;
            }
        }

        count++;
    }

    return count;
}

// Аналог функции strchr
char *my_strchr(const char *str, int ch)
{
    const char *p;

    for (p = str; *p != '\0'; p++)
    {
        if (*p == ch)
        {
            return (char *)p;
        }
    }

    if (*p == ch)
    {
        return (char *)p;
    }

    return NULL;
}

// Аналог функции strrchr
char *my_strrchr(const char *str, int ch)
{
    const char *p;
    const char *last = NULL;

    for (p = str; *p != '\0'; p++)
    {
        if (*p == ch)
        {
            last = p;
        }
    }

    if (*p == ch)
    {
        return (char *)p;
    }

    return (char *)last;
}
