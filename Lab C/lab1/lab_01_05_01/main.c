#include<stdio.h>
#include<stdlib.h>

int divide(int a, int d)
{
    int quotient = 0;
    while (a >= d)
    {
        a -= d;
        ++quotient;
    }
    return quotient;
}

int main(void)
{
    int a, d, q;
    int rc = scanf("%d %d", &a, &d);
    if (rc != 2)
    {
        printf("Invalid input!");
        return -1;
    }
    if ((a > 0) && (d > 0))
    {
        q = divide(a, d);
        printf("Quotient: %d\n", q);
        printf("Remainder: %d", a - d * q);
        return 0;
    }
    else
    {
        printf("Invalid input!");
        return -1;
    }
}

