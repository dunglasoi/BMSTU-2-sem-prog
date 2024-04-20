#include "string_util.h"

#include <string.h>

bool_t endswith(char const *const a, char const *const b)
{
    size_t a_len = strlen(a), b_len = strlen(b);
    int result = TRUE;

    while (b_len)
        if (a[--a_len] != b[--b_len])
            result = FALSE;

    return result;
}
