#ifndef __BASE_H__
#define __BASE_H__

#include <stdio.h>
#include <stdlib.h>

#define MIN_CLI_ARG_COUNT 2

typedef enum
{
    OK = EXIT_SUCCESS,
    ERROR_INVALID_INPUT = EXIT_FAILURE,
    ERROR_INVALID_CLI_ARGS,
    ERROR_IO
} result_t;

void print_result(result_t const rc);

result_t calculate_dispersion(FILE *const file, double *const dispersion);

#endif
