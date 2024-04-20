#include <assert.h>

#include "file.h"
#include "error.h"

int process(FILE *f, int *count)
{
    assert(f != NULL);
    assert(count != NULL);

    int num;
    int a[3];
    int n = 0;
    *count = 0;

    while (fscanf(f, "%d", &num) == 1)
    {
        a[0] = a[1];
        a[1] = a[2];
        a[2] = num;
        n++;

        if (n >= 3)
        {
            if (a[0] < a[1] && a[1] > a[2])
                (*count)++;
        }
    }

    if (n < 3)
        return ERR_IO;

    return OK;
}
