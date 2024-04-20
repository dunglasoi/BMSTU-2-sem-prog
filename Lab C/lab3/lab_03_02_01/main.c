#include <stdio.h>
#include "main_sp.h"
#include "const.h"

int main()
{
    int a[N_MAX][N_MAX];
    size_t row;
    size_t col;
    int check_error = size_matrix(&row, &col);
    if (check_error)
    {
        printf("Error: Invalid input\n");
        return -1;
    }

    int check_error2 = input_matrix(a, row, col);
    if (check_error2)
    {
        printf("Error: Invalid input\n");
        return -1;
    }
    else
    {
        int minrow = 0;
        int mincol = 0;
        find_num(a, row, col, &minrow, &mincol);
        delete(a, row, col, minrow, mincol);
        result(a, row - 1, col - 1);
    }
    return 0;
}
