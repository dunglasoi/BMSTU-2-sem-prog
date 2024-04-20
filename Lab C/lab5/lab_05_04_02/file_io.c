#include "file_io.h"

#include "products.h"
#include "my_bool.h"

result_t get_file_size(FILE *const file, size_t *const size)
{
    result_t result = OK;

    if (fseek(file, 0, SEEK_END))
    {
        result = ERROR_IO;
    }
    else
    {
        int file_size = ftell(file);

        if (file_size < (int)sizeof(product_t) || file_size % sizeof(product_t))
            result = ERROR_INVALID_FILE_SIZE;
        else
            *size = file_size;

        if (!result && fseek(file, 0, SEEK_SET))
            result = ERROR_IO;
    }

    return result;
}

result_t copy_file(char const *const src_filename, char const *const dst_filename, FILE **const dst_out)
{
    result_t result = OK;
    FILE *src = fopen(src_filename, "rb"), *dst = fopen(dst_filename, "wb+");

    if (!src || !dst)
        result = ERROR_IO;
    if (dst)
        *dst_out = dst;

    bool_t is_finished = !!result;

    while (!is_finished)
    {
        enum
        {
            BUFFER_SIZE = 4096
        };
        char buffer[BUFFER_SIZE];
        int read = fread(buffer, 1, sizeof(buffer), src);
        fwrite(buffer, read, 1, dst);
        is_finished = read;
    }

    if (src && fclose(src))
        result = ERROR_IO;

    return result;
}
