#include<stdio.h>
main()
{
    FILE * fp;
    int c,i;
    for(i=0 ; i<5 ; i++)
    {
        c=getchar();
        putchar(c);
    }
    printf("\n");
}
