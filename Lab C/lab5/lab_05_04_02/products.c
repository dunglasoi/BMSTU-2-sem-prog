#include "products.h"

#include <inttypes.h>

#include "result.h"

void print_product_info(product_t const *const product)
{
    printf("%s\n%s\n%" PRIu32 "\n%" PRIu32 "\n",
    product->name, product->manufacturer, product->unit_price, product->quantity);
}

result_t get_product_by_pos(FILE *const file, size_t const location, product_t *const product)
{
    result_t result = OK;
    enum
    {
        N_ITS = 1
    };

    if (fseek(file, location, SEEK_SET) || fread(product, sizeof(product_t), N_ITS, file) != N_ITS)
        result = ERROR_IO;

    return result;
}

result_t put_product_by_pos(FILE *const file, size_t const location, const product_t *const product)
{
    result_t result = OK;
    enum
    {
        N_ITS = 1
    };

    if (fseek(file, location, SEEK_SET) || fwrite(product, sizeof(product_t), N_ITS, file) != N_ITS)
        result = ERROR_IO;

    return result;
}

result_t get_product_by_idx(FILE *const file, size_t const idx, product_t *const product)
{
    return get_product_by_pos(file, idx * sizeof(product_t), product);
}

result_t put_product_by_idx(FILE *const file, size_t const idx, const product_t *const product)
{
    return put_product_by_pos(file, idx * sizeof(product_t), product);
}

result_t swap_products(FILE *const file, size_t const idx0, size_t const idx1)
{
    result_t result;
    product_t a, b;

    if ((result = get_product_by_idx(file, idx0, &a))
        || (result = get_product_by_idx(file, idx1, &b))
        || (result = put_product_by_idx(file, idx0, &b))
        || (result = put_product_by_idx(file, idx1, &a)))
        (void)0;

    return result;
}

bool_t product_is_less_or_equal(const product_t *const product, const product_t *const other)
{
    return product->unit_price > other->unit_price
        || (product->unit_price == other->unit_price && product->quantity >= other->quantity);
}

result_t quicksort_partition(FILE *const file, long const low, long const high, long *const middle)
{
    product_t pivot;
    result_t result = get_product_by_idx(file, high, &pivot);
    long i = low - 1;

    for (long j = low; j <= high - 1 && !result; ++j)
    {
        product_t test;
        result = get_product_by_idx(file, j, &test);

        if (!result && product_is_less_or_equal(&test, &pivot))
            result = swap_products(file, ++i, j);
    }

    if (!result)
    {
        result = swap_products(file, i + 1, high);
        *middle = i + 1;
    }

    return result;
}

result_t quicksort_bin_file(FILE *const file, long const low, long const high)
{
    result_t result = OK;

    if (low < high)
    {
        long middle;
        result = quicksort_partition(file, low, high, &middle);

        if (!result)
            result = quicksort_bin_file(file, low, middle - 1);

        if (!result)
            result = quicksort_bin_file(file, middle + 1, high);
    }

    return result;
}
