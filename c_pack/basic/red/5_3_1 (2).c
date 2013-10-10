#include<stdio.h>
#include<math.h>
#define PI 3.14

float area(float r)
{
        float s;
        s = PI * pow(r, 2);
        return s;
}

int main()
{
        float r, s;
        printf("radius = ");
        scanf("%f", &r);
        s = area(r);
        printf("area = %f\n", s);
        return 0;
}
