#include <stdio.h>
#include "main_sp.h"
#include "const.h"

int main()
{
    int a[N_MAX][N_MAX];
    int b[N];
    size_t row;
    size_t col;
    if (size_matrix(&row, &col) != 0)
    {
        printf("Error: Invalid input\n");
        return -1;
    }
    if (input_matrix(a, row, col) != 0)
    {
        printf("Error: Invalid input\n");
        return -1;
    }
    int c = 0;
    array(a, b, row, col, &c);
    if (!c)
    {
        printf("Error: Invalid input\n");
        return -1;
    }
    else
    {
        left(b, c);
        update_matrix(a, b, row, col);
        result(a, row, col);
    }
    return 0;
}
