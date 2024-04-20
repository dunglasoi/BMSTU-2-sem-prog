#include <string.h>

#include "result.h"
#include "mode_sort.h"
#include "mode_print.h"
#include "mode_insert.h"

#define MIN_CLI_ARG_COUNT 2
#define SORT_CLI_ARG_COUNT 3
#define PRINT_CLI_ARG_COUNT 3
#define INSERT_CLI_ARG_COUNT 2

result_t process_arguments(char const **const args, size_t const count)
{
    result_t result = ERROR_INVALID_CLI_ARGS;

    if (!count)
        (void)0;
    else if (!strcmp(args[0], "sb") && count == SORT_CLI_ARG_COUNT)
        result = mode_sort(args[1], args[2]);
    else if (!strcmp(args[0], "fb") && count == PRINT_CLI_ARG_COUNT)
        result = mode_print(args[1], args[2]);
    else if (!strcmp(args[0], "ab") && count == INSERT_CLI_ARG_COUNT)
        result = mode_insert_interactive(args[1]);

    return result;
}

int main(int const argc, char const **const argv)
{
    result_t result = process_arguments(argv + 1, argc - 1);

    return result;
}
