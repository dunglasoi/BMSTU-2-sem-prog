#include <stdio.h>
#include "main_sp.h"
#include "const.h"

int main()
{
    int a[N_MAX][N_MAX];
    size_t row;
    size_t col;
    if (size_matrix(&row, &col) != 0)
    {
        printf("Error: Invalid input\n");
        return -1;
    }
    spiral_fill(a, row, col);
    result(a, row, col);
    return 0;
}
