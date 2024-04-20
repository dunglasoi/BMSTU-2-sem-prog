#include<stdio.h>
#include<math.h>
#define MIN 1e-6

double check(double eps)
{
    if ((1 - eps > MIN) && (eps > 0))
        return 1;
    else
        return 0;
}

double calc(double x, double eps)
{
    double b, sum = 0;
    int n = 0;
    b = x;
    while (fabs(b) > eps)
    {
        sum += b;
        n++;
        b *= -x * x / (2 * n * (2 * n + 1));
    }
    return sum;
}

int main(void)
{
    double x, eps;
    int rc = scanf("%lf %lf", &x, &eps);
    if ((rc == 2) && check(eps))
    {
        double sumsx = calc(x, eps);
        printf("%lf\n", sumsx);
        double sumsi = sin(x);
        printf("%lf\n", sumsi);
        double ab, re;
        ab = fabs(sumsi - sumsx);
        re = ab / sumsi;
        printf("%lf\n", fabs(ab));
        printf("%lf\n", fabs(re));
        return 0;
    }
    else
    {
        printf("Invalid input!");
        return -1;
    }
}

