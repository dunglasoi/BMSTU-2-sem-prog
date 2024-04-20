#ifndef MAIN_SP_H
#define MAIN_SP_H

#include <stdio.h>
#include "const.h"

int size_matrix(size_t *row, size_t *col);
int input_matrix(int a[N_MAX][N_MAX], size_t row, size_t col);
void result(int a[N_MAX][N_MAX], size_t row, size_t col);
int get_sum(int n);
void array(int a[N_MAX][N_MAX], int b[N], size_t row, size_t col, int *c);
void left(int b[N], int c);
void update_matrix(int a[N_MAX][N_MAX], int b[N], size_t row, size_t col);

#endif
