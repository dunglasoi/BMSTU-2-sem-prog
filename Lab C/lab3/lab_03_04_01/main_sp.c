#include <stdio.h>
#include "const.h"

int size_matrix(size_t *row, size_t *col)
{
    if (scanf("%zu", row) != 1 || *row < 1 || *row > N_MAX)
        return -1;
    if (scanf("%zu", col) != 1 || *col < 1 || *col > N_MAX)
        return -1;
    if (*row != *col)
        return -1;
    return 0;
}

int input_matrix(int a[N_MAX][N_MAX], size_t row, size_t col)
{
    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
        {
            if (scanf("%d", &a[i][j]) != 1)
                return -1;
        }
    return 0;
}

void swap(int a[N_MAX][N_MAX], size_t row, size_t col)
{
    size_t n1 = 0;
    size_t n2 = row - 1;
    size_t m1 = 0;
    size_t m2 = col - 1;

    while (n1 < n2)
    {
        for (size_t i = n1; i < n2; i++)
        {
            int temp = a[i][m1];
            a[i][m1] = a[i][m2];
            a[i][m2] = temp;
        }
        for (size_t j = m1; j <= m2; j++)
        {
            int temp = a[n1][j];
            a[n1][j] = a[n2][j];
            a[n2][j] = temp;
        }
        n1++;
        n2--;
        m1++;
        m2--;
    }
}

void result(int a[N_MAX][N_MAX], size_t row, size_t col)
{
    printf("Result: \n");
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}