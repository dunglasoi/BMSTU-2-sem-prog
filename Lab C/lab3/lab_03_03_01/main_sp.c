#include <stdio.h>
#include "const.h"

int size_matrix(size_t *row, size_t *col)
{
    if (scanf("%zu %zu", row, col) == 2)
    {
        if (*row > 0 && *col < 11)
        {
            if (*col > 0 && *col < 11)
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
            if (scanf("%d", &a[i][j]) != 1)
                return -1;
        }
    return 0;
}

int sort(size_t row, size_t col, int a[N_MAX][N_MAX])
{
    for (size_t i = 0; i < row; i++)
    {
        size_t max_a = i;
        for (size_t j = i + 1; j < row; j++)
        {
            int max_b = a[j][0];
            for (size_t k = 1; k < col; k++)
            {
                if (a[j][k] > max_b)
                {
                    max_b = a[j][k];
                }
            }
            if (max_b > a[max_a][0])
            {
                max_a = j;
            }
        }
        if (max_a != i)
        {
            for (size_t k = 0; k < col; k++)
            {
                int temp = a[i][k];
                a[i][k] = a[max_a][k];
                a[max_a][k] = temp;
            }
        }
    }
    return 0;
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
    printf("\n");
}
