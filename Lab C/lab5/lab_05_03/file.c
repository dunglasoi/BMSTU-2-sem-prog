#include <assert.h>
#include <stdlib.h>

#include "file.h"
#include "error.h"

int write_file(FILE *f, char *number)
{
    assert(f != NULL);
    assert(number != NULL);

    char *end;
    long n = strtol(number, &end, 0);

    if (*end != 0 || n <= 0)
        return ERR_RANGE;

    for (int i = 0; i < n; i++)
    {
        int random = rand() % 100;

        if (fwrite(&random, sizeof(int), 1, f) != 1)
            return ERR_WRITE;
    }

    return OK;
}

int get_file_size(FILE *f, size_t *size)
{
    assert(f != NULL);
    assert(size != NULL);

    long sz;

    if (fseek(f, 0L, SEEK_END))
        return 1;

    sz = ftell(f);
    if (sz < 0)
        return 1;

    *size = sz;

    return fseek(f, 0L, SEEK_SET);
}

int output_file(FILE *f, FILE *f_out)
{
    assert(f != NULL);

    size_t size;
    int num;

    if (get_file_size(f, &size))
        return ERR_GET_FILE_SIZE;

    size_t total = size / sizeof(int);
    if (total == 0)
        return ERR_EMPTY;
    if (size % sizeof(int))
        return ERR_FILE;

    for (size_t i = 0; i < total - 1; i++)
    {
        if (fread(&num, sizeof(int), 1, f) != 1)
            return ERR_READ;

        fprintf(f_out, "%d ", num);
    }
    if (fread(&num, sizeof(int), 1, f) != 1)
        return ERR_READ;
    fprintf(f_out, "%d\n", num);

    return OK;
}

/**
 * @brief По заданной позиции прочитать число в указанной позиции
 *
 * @param [in] f Файловая переменная
 * @param [in] pos Позиция
 * @param [out] num Число
 */
int get_number_by_pos(FILE *f, int pos, int *num)
{
    assert(f != NULL);
    assert(num != NULL);

    if (fseek(f, pos * sizeof(int), SEEK_SET))
        return ERR_SEEK;

    if (fread(num, sizeof(int), 1, f) != 1)
        return ERR_READ;

    return OK;
}

/**
 * @brief Записать число на указанную позицию с затиранием
 *
 * @param [in] f Файловая переменная
 * @param [in] pos Позиция
 * @param [in] num Число
 */
int put_number_by_pos(FILE *f, int pos, int num)
{
    assert(f != NULL);

    if (fseek(f, pos * sizeof(int), SEEK_SET))
        return ERR_SEEK;

    if (fwrite(&num, sizeof(int), 1, f) != 1)
        return ERR_WRITE;

    return OK;
}

int sort_file(FILE *f)
{
    assert(f != NULL);

    int rc = OK;
    size_t size;
    int num1, num2;

    if (get_file_size(f, &size))
        return ERR_GET_FILE_SIZE;

    int total = size / sizeof(int);
    if (total == 0)
        return ERR_EMPTY;
    if (size % sizeof(int))
        return ERR_FILE;

    for (int i = 0; i < total - 1; i++)
    {
        for (int j = i + 1; j < total; j++)
        {
            rc = get_number_by_pos(f, i, &num1);
            if (rc)
                return rc;
            rc = get_number_by_pos(f, j, &num2);
            if (rc)
                return rc;
            if (num1 > num2)
            {
                rc = put_number_by_pos(f, i, num2);
                if (rc)
                    return rc;
                rc = put_number_by_pos(f, j, num1);
                if (rc)
                    return rc;
            }
        }
    }
    return rc;
}
