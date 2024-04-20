#include "mode_sort.h"

#include <stdio.h>

#include "file_io.h"
#include "products.h"

result_t mode_sort(char const *const src_filename, char const *const dst_filename)
{
    result_t result = OK;
    FILE *file = NULL;
    size_t file_size;

    if (copy_file(src_filename, dst_filename, &file))
        result = ERROR_IO;

    if (!result && !(result = get_file_size(file, &file_size)))
    {
        size_t element_count = file_size / sizeof(product_t);
        result = quicksort_bin_file(file, 0, element_count - 1);
    }

    if (file && fclose(file))
        result = ERROR_IO;

    return result;
}
