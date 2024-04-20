#ifndef __PRODUCTS_H__
#define __PRODUCTS_H__

#include <stdio.h>
#include <stdint.h>

#include "my_bool.h"
#include "result.h"

#define NAME_LEN 31
#define MANUFACTURER_LEN 16

typedef struct
{
    char name[NAME_LEN];
    char manufacturer[MANUFACTURER_LEN];
    uint32_t unit_price;
    uint32_t quantity;
} product_t;

result_t get_product_by_pos(FILE *const file, size_t const location, product_t *const product);

result_t put_product_by_pos(FILE *const file, size_t const location, const product_t *const product);

result_t get_product_by_idx(FILE *const file, size_t const idx, product_t *const product);

result_t put_product_by_idx(FILE *const file, size_t const idx, const product_t *const product);

result_t swap_products(FILE *const file, size_t const idx0, size_t const idx1);

bool_t product_is_less_or_equal(const product_t *const product, const product_t *const other);

result_t quicksort_bin_file(FILE *const file, long const low, long const high);

void print_product_info(product_t const *const product);


#endif
