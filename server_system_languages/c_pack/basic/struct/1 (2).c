#include<stdio.h>

int main()
{
    struct data
    {
        long l;
        char *s;
        short int i;
        char c;
        short int a[5];
    }d;

    struct data *p = &d;

    printf("%d\n",sizeof(d));
    printf("%x\t%x\n", p, p+1);
    printf("%x\t%x\n", p, (char *)p+1);
    printf("%x\t%x\n", p, (long *)p+1);

    printf("int: %d\n", sizeof(int));
    printf("char: %d\n", sizeof(char));
    printf("char*: %d\n", sizeof(char*));
    printf("long: %d\n", sizeof(long));
    printf("float: %d\n", sizeof(float));
    printf("short: %d\n", sizeof(short));
    printf("double: %d\n", sizeof(double));

    return 0;
}
