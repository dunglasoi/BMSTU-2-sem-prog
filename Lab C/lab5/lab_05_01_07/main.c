/**
 * @author Huynh Viet Hung (xkh22iu57) (xkh22iu57@student.bmstu.ru)
 */

#include <stdio.h>
#include <errno.h>

#include "file.h"
#include "error.h"

int main(void)
{
    int rc = OK;
    int count;
    FILE *f = stdin;

    rc = process(f, &count);

    if (rc)
    {
        printf("Error: Ввод/Вывод\n");
        return rc;
    }
    printf("%d\n", count);

    return rc;
}