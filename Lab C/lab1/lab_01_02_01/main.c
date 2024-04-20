#include <stdio.h>
#include <math.h>
#define PI acos(-1)

int main() 
{
    double a, b, phi, s, h;
    double temp;
    printf("Enter the values of a, b, phi: ");
    scanf("%lf %lf %lf", &a, &b, &phi);
    if (a > b) 
    {
        temp = a;
        a = b;
        b = temp;
    }
    h = (b - a) / 2.0 * tan(phi * PI / 180.0);
    s = (a + b) * h / 2.0;
    printf("S: %.5lf", s);
    return 0;
}
