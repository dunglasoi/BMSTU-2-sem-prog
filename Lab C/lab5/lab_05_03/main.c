#include <stdio.h>
#include <string.h>

#include "process.h"
#include "error.h"

void usage(void)
{
    // создавать файл и заполнять его случайными числами
    printf("app.exe c number file\n");
    // выводить числа из файла на экран
    printf("app.exe p file\n");
    // упорядочивать числа в файле
    printf("app.exe s file\n");

    // Перевод текстовый файл в бинарный
    printf("app.exe t2b FILE_TXT FILE_BIN\n");

    // Перевод бинарный файл в текстовый
    printf("app.exe b2t FILE_BIN FILE_TXT\n");
}

int main(int argc, char **argv)
{
    int rc = OK;
    FILE *f;

    // app.exe c number file
    if (argc == 4 && strcmp(argv[1], "c") == 0)
    {
        f = fopen(argv[3], "wb");
        if (f == NULL)
        {
            rc = errno;
            return rc;
        }

        rc = process_c(f, argv[2]);

        fclose(f);
        return rc;
    }

    // app.exe p file
    if (argc == 3 && strcmp(argv[1], "p") == 0)
    {
        f = fopen(argv[2], "rb");
        if (f == NULL)
        {
            rc = errno;
            return rc;
        }

        rc = process_p(f);

        fclose(f);
        return rc;
    }

    // app.exe s file
    if (argc == 3 && strcmp(argv[1], "s") == 0)
    {
        f = fopen(argv[2], "rb+");
        if (f == NULL)
        {
            rc = errno;
            return rc;
        }

        rc = process_s(f);

        fclose(f);
        return rc;
    }

    // app.exe t2b FILE_TXT FILE_BIN
    if (argc == 4 && strcmp(argv[1], "t2b") == 0)
    {
        rc = process_t2b(argv[2], argv[3]);
        return rc;
    }

    // app.exe b2t FILE_BIN FILE_TXT
    if (argc == 4 && strcmp(argv[1], "b2t") == 0)
    {
        rc = process_b2t(argv[2], argv[3]);
        return rc;
    }

    usage();
    return ERR_USAGE;
}