#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int check(double xa, double xb, double xc, double ya, double yb, double yc)
{
    double a = sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
    double b = sqrt(pow(xc - xb, 2) + pow(yc - yb, 2));
    double c = sqrt(pow(xa - xc, 2) + pow(ya - yc, 2));
    if ((a + b) <= c || (c + b) <=a || (c + a) <= b)
    {
        return -1;
    }
    return 0;
}

int main()
{
    double xa, ya, xb, yb, xc, yc;
    int rc = scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc);
    if ((rc != 6) || check(xa, xb, xc, ya, yb, yc))
    {
        printf("Invalid input!");
        return -1;
    }
    double a = sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
    double b = sqrt(pow(xc - xb, 2) + pow(yc - yb, 2));
    double c = sqrt(pow(xa - xc, 2) + pow(ya - yc, 2));
    double s = (a + b + c) / 2;
    double S = sqrt(s*(s-a)*(s-b)*(s-c));
    printf("S = %lf", S);   
    return 0;
}