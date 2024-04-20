#ifndef MAIN_SP_H
#define MAIN_SP_H

#include <stdio.h>
#include <stdlib.h>
#include "const.h"

int size_matrix(size_t *row, size_t *col);
int input_matrix(int a[N_MAX][N_MAX], size_t row, size_t col);
int get_sum(int n);
void find_num(int a[N_MAX][N_MAX], size_t row, size_t col, int *minrow, int *mincol);
void delete(int a[N_MAX][N_MAX], size_t row, size_t col, int minrow, int mincol);
void result(int a[N_MAX][N_MAX], size_t row, size_t col);

#endif
