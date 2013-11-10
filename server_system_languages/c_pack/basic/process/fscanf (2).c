#include<stdio.h>
main()
{
    int i;
    unsigned int j;
    char s[5];
    fscanf(stdin , "%d %x %5[a-z] %*s %f" , &i , &j , s , s);
    printf("%d %d %s \n", i , j , s);
}
