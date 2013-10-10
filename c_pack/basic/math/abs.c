#include <stdio.h>

int main()
{
    int num;
    printf("Input:");
    scanf("%d", &num);
    num = myabs(num);
    printf("After abs: %d\n", num);
    
    return 0;
}

int myabs(int x)
{
    return (x > 0 ? x : -x);
}
