#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "my_string.h"


int main(void)
{
    int ret = OK;
    char strings[STR_LEN];

    if (get_line(strings, STR_LEN) != OK)
    {
        return 1;
    }

    if (is_float(strings))
        printf("YES\n");
    else
        printf("NO\n");

    return ret;
}
