#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STR_LEN (50 + 1)

#define OK 0
#define ERR_ARG -1
#define ERR_INVALID_CHAR -4
#define ERR_LINE_LEN -5

int calc(FILE *f);
void error(int err);

#endif