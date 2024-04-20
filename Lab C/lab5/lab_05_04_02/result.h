#ifndef __MY_RESULT_H__
#define __MY_RESULT_H__

#include <stdlib.h>

typedef enum
{
    OK = EXIT_SUCCESS,
    ERROR_INVALID_CLI_ARGS = 53,
    ERROR_IO = EXIT_FAILURE,
    ERROR_INVALID_FILE_SIZE,
    ERROR_INVALID_INPUT,
    ERROR_NO_SUBSTR
} result_t;

#endif
