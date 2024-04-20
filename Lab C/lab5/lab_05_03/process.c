#include <assert.h>

#include "error.h"
#include "process.h"
#include "file.h"

int process_c(FILE *f, char *number)
{
    assert(f != NULL);
    assert(number != NULL);

    return write_file(f, number);
}

int process_p(FILE *f)
{
    assert(f != NULL);

    return output_file(f, stdout);
}

int process_s(FILE *f)
{
    assert(f != NULL);

    return sort_file(f);
}

int process_t2b(char *file_txt, char *file_bin)
{
    assert(file_txt != NULL);
    assert(file_bin != NULL);

    int rc = OK;
    FILE *f_src, *f_dst;

    f_src = fopen(file_txt, "r");
    if (f_src == NULL)
    {
        rc = errno;
        return rc;
    }

    f_dst = fopen(file_bin, "wb");
    if (f_dst == NULL)
    {
        fclose(f_src);
        rc = errno;
        return rc;
    }

    int num;
    while (!feof(f_src))
    {
        if (fscanf(f_src, "%d", &num) != 1)
        {
            rc = errno;
            break;
        }
        if (fwrite(&num, sizeof(num), 1, f_dst) != 1)
        {
            rc = errno;
            break;
        }
    }

    fclose(f_src);
    fclose(f_dst);
    return rc;
}

int process_b2t(char *file_bin, char *file_txt)
{
    assert(file_bin != NULL);
    assert(file_txt != NULL);

    int rc = OK;
    FILE *f_src, *f_dst;

    f_src = fopen(file_bin, "rb");
    if (f_src == NULL)
    {
        rc = errno;
        return rc;
    }
    f_dst = fopen(file_txt, "w");
    if (f_dst == NULL)
    {
        fclose(f_src);
        rc = errno;
        return rc;
    }

    rc = output_file(f_src, f_dst);

    fclose(f_src);
    fclose(f_dst);
    return rc;
}
