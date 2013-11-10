#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[10];
    int i, j;
    int t;
    printf("Array before sort:   \n");
    for(i = 0; i< 10; i++)
        {
            a[i] = rand() % 100 +1;
            printf("%4d ",a[i]);
        }
    printf("\nArray after sort:  \n");
    for(i = 0; i < 9; i++)
    {
        for(j = i +1; j < 10 ; j++)
            {
                if(a[i] > a[j])
                {
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
    }
    for(i = 0; i< 10; i++)
    {
        printf("%4d\n", a[i]);
    }
    return 0;
}
