#include "base.h"

#define SCANF_IT_RC 1

result_t calculate_average(FILE *const file, double *const average)
{
    result_t result = OK;

    double sum = 0;
    size_t count = 0;
    double temp;

    while (fscanf(file, "%lf", &temp) == SCANF_IT_RC && ++count)
        sum += temp;

    if (!count)
        result = ERROR_INVALID_INPUT;
    else
        *average = sum / count;

    return result;
}

result_t calculate_dispersion_internal(FILE *const file, double const average, double *const dispersion)
{
    result_t result = OK;

    size_t count = 0;
    double accumulate = 0;
    double temp;

    while (fscanf(file, "%lf", &temp) == SCANF_IT_RC && ++count)
    {
        temp = average - temp;
        accumulate += temp * temp;
    }

    if (!count)
        result = ERROR_INVALID_INPUT;
    else
        *dispersion = accumulate / count;

    return result;
}

result_t calculate_dispersion(FILE *const file, double *const dispersion)
{
    double average;
    result_t result = calculate_average(file, &average);

    if (!result && fseek(file, 0, SEEK_SET) < 0)
        result = ERROR_IO;

    if (!result)
        result = calculate_dispersion_internal(file, average, dispersion);

    return result;
}
