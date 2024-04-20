#include <stdio.h>
#include <math.h>
#define EPS 1e-6

double calculate_d(void)
{
    double d = 0.0;
    double x = 0.0;
    int n = 1;
    scanf("%lf", &x);
    if (x < -EPS)
    {
        printf("Invalid input!\n");
        return -1.0;
    }
    while (x >= -EPS)
    {   
        if (x < -EPS)
        {
            break;
        }
        d = d + sqrt(x / n);
        n += 1;
        if ((scanf("%lf", &x)) != 1)
        {
            printf("Invalid input!\n");
            return -1.0;
        }
    }

    return d;
}

int main(void)
{
    double d = calculate_d();
    if (d < 0.0)
    {
        return 1;
    }
    double gx = sin(d);
    printf("%lf", gx);
    return 0;
}
