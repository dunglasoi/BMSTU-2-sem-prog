#include <stdlib.h>

#include "base.h"

int main(int const argc, char const **const argv)
{
    result_t result = OK;

    if (argc < MIN_CLI_ARG_COUNT)
        result = ERROR_INVALID_CLI_ARGS;

    FILE *file = NULL;

    if (!result && !(file = fopen(argv[1], "r")))
        result = ERROR_IO;

    if (!result)
    {
        double dispersion;

        if (!(result = calculate_dispersion(file, &dispersion)))
            printf("%lf\n", dispersion);
    }

    if (file && fclose(file))
        result = ERROR_IO;

    return result;
}
