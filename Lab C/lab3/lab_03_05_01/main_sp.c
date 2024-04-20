#include <stdio.h>
#include <stdlib.h>
#include "const.h"

int size_matrix(size_t *row, size_t *col)
{
    if (scanf("%zu", row) != 1 || *row < 1 || *row > N_MAX)
        return -1;
    if (scanf("%zu", col) != 1 || *col < 1 || *col > N_MAX)
        return -1;
    return 0;
}

int input_matrix(int a[N_MAX][N_MAX], size_t row, size_t col)
{
    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return -1;
    return 0;
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

void array(int a[N_MAX][N_MAX], int b[N], size_t row, size_t col, int *c)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            if (get_sum(a[i][j]) > 10)
            {
                b[*c] = a[i][j];
                (*c)++;
            }
        }
    }
}

void left(int b[N], int c)
{
    for (int i = 0; i < 3; i++)
    {
        int z = b[0];
        for (int j = 1; j < c; j++)
            b[j - 1] = b[j];
        b[c - 1] = z;
    }
}

void update_matrix(int a[N_MAX][N_MAX], int b[N], size_t row, size_t col)
{
    int k = 0;
    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
            if (get_sum(a[i][j]) > 10)
            {
                a[i][j] = b[k];
                k++;
            }
}
