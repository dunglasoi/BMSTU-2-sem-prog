#include "mode_print.h"

#include "products.h"
#include "file_io.h"
#include "string_util.h"

result_t print_queried_elements(FILE *const file, size_t const count, char const *const substr)
{
    result_t result = OK;
    size_t printed_count = 0;
    enum
    {
        N_ITS = 1
    };

    for (size_t product_idx = 0; product_idx < count && !result; ++product_idx)
    {
        product_t product;
        if (fread(&product, sizeof(product_t), N_ITS, file) != N_ITS)
            result = ERROR_IO;

        if (!result && endswith(product.name, substr))
        {
            print_product_info(&product);
            ++printed_count;
        }
    }

    if (!printed_count)
        result = ERROR_NO_SUBSTR;

    return result;
}

result_t mode_print(char const *const filename, char const *const substr)
{
    result_t result = OK;
    FILE *file = fopen(filename, "rb");
    size_t file_size;

    if (!file || get_file_size(file, &file_size))
        result = ERROR_IO;

    if (!result)
    {
        size_t const product_count = file_size / sizeof(product_t);
        result = print_queried_elements(file, product_count, substr);
    }

    if (file && fclose(file))
        result = ERROR_IO;

    return result;
}
