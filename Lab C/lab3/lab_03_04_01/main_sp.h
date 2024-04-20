#ifndef MAIN_SP_H
#define MAIN_SP_H

#include <stdio.h>
#include "const.h"

int size_matrix(size_t *row, size_t *col);
int input_matrix(int a[N_MAX][N_MAX], size_t row, size_t col);
void swap(int a[N_MAX][N_MAX], size_t row, size_t col);
void result(int a[N_MAX][N_MAX], size_t row, size_t col);

#endif
