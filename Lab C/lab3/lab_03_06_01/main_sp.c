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

void spiral_fill(int a[N_MAX][N_MAX], size_t row, size_t col)
{
    int val = 1;
    int row1 = 0;
    int row2 = row - 1;
    int col1 = 0;
    int col2 = col - 1;

    while (row1 <= row2 && col1 <= col2)
    {
        for (int j = col1; j <= col2; j++)
            a[row1][j] = val++;
        for (int i = row1 + 1; i <= row2; i++)
            a[i][col2] = val++;
        if (row1 < row2 && col1 < col2)
        {
            for (int j = col2 - 1; j > col1; j--)
                a[row2][j] = val++;
            for (int i = row2; i > row1; i--)
                a[i][col1] = val++;
        }
        row1++;
        row2--;
        col1++;
        col2--;
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
}
