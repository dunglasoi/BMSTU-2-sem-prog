#include <stdio.h>
#include <stdlib.h>
#include "const.h"

int size_matrix(size_t *row, size_t *col)
{
    if (scanf("%zu %zu", row, col) == 2)
    {
        if (*row > 1 && *col < 11)
        {
            if (*col > 1 && *col < 11)
                return 0;
        }
        return -1;
    }
    else
        return -1;
}

int input_matrix(int a[N_MAX][N_MAX], size_t row, size_t col)
{
    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
        {
            int rc = scanf("%d", &a[i][j]);
            if (rc != 1)
                return -1;
        }
    return 0;
}

int get_sum(int n)
{
    int sum = 0;
    n = abs(n);
    while (n > 0)
    {
        sum += abs(n % 10);
        n /= 10;
    }
    return sum;
}

void find_num(int a[N_MAX][N_MAX], size_t row, size_t col, int *minrow, int *mincol)
{
    int min_sum = get_sum(a[0][0]);
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (min_sum > get_sum(a[i][j]))
            {
                *minrow = i;
                *mincol = j;
                min_sum = get_sum(a[i][j]);
            }
        }
    }
}

void delete(int a[N_MAX][N_MAX], size_t row, size_t col, int minrow, int mincol)
{
    for (size_t i = minrow; i < row - 1; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            a[i][j] = a[i + 1][j];
        }
    }
    for (size_t j = mincol; j < col - 1; j++)
    {
        for (size_t i = 0; i < row; i++)
        {
            a[i][j] = a[i][j + 1];
        }
    }
}

void result(int a[N_MAX][N_MAX], size_t row, size_t col)
{
    printf("Result: \n");
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}
