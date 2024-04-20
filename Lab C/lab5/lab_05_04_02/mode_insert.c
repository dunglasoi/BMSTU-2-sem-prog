#include "mode_insert.h"

#include <inttypes.h>

#include "products.h"
#include "file_io.h"

#define SCANF_IT_RC 1

result_t input_product(product_t *const product)
{
    result_t result = OK;

    if (scanf("%s", product->name) != SCANF_IT_RC
        || scanf("%s", product->manufacturer) != SCANF_IT_RC
        || scanf("%" PRIu32, &product->unit_price) != SCANF_IT_RC
        || scanf("%" PRIu32, &product->quantity) != SCANF_IT_RC)
        result = ERROR_INVALID_INPUT;

    return result;
}

result_t find_index_to_insert(FILE *const file, size_t const count, const product_t *const product,
size_t *const idx_to_write)
{
    result_t result = OK;
    size_t temp = 0;
    bool_t is_valid = TRUE;

    for (size_t product_idx = 0; product_idx < count && !result && is_valid; ++product_idx)
    {
        product_t test;
        result = get_product_by_idx(file, product_idx, &test);

        if (!result && product_is_less_or_equal(product, &test))
            is_valid = FALSE;
        else
            ++temp;
    }

    if (!result)
        *idx_to_write = temp;

    return result;
}

result_t insert_product_sorted(FILE *const file, size_t const product_count, product_t const product)
{
    size_t idx_to_write;
    result_t result = find_index_to_insert(file, product_count, &product, &idx_to_write);

    for (size_t product_idx = product_count - 1; product_idx >= idx_to_write && !result; --product_idx)
    {
        product_t product;
        result = get_product_by_idx(file, product_idx, &product);

        if (!result)
            result = put_product_by_idx(file, product_idx + 1, &product);
    }

    result = put_product_by_idx(file, idx_to_write, &product);

    return result;
}

result_t mode_insert_interactive(char const *const filename)
{
    product_t product = { 0 };
    result_t result = input_product(&product);

    if (!result)
    {
        FILE *file = fopen(filename, "rb+");
        size_t file_size;

        if (!file || get_file_size(file, &file_size))
            result = ERROR_IO;

        if (!result)
        {
            size_t product_count = file_size / sizeof(product_t);
            insert_product_sorted(file, product_count, product);
        }

        if (file && fclose(file))
            result = ERROR_IO;
    }

    return result;
}
