#include<stdio.h>

int main(void)
{
    double v1, v2;
    float t1, t2;
    scanf("%lf %f", &v1, &t1);
    scanf("%lf %f", &v2, &t2);
    double v;
    float t;
    v = v1 + v2;
    t = (v1 * t1 + v2 * t2) / v;

    printf("%lf %f", v, t);

    return 0;
}


