#include<stdio.h>

int main()
{
    struct time
    {
        long time_zone;
        char *notes;
        short int i;
        char c;
        short int a[5];
    }t;

    struct data *p = &d;

    printf("%d\n",sizeof(d));
    printf("%x\t%x\n", p, p+1);
    printf("%x\t%x\n", p, (char *)p+1);
    printf("%x\t%x\n", p, (long *)p+1);

    printf("int: %d\n", sizeof(int));
    printf("char: %d\n", sizeof(char));
    printf("Notes(sizeof char*): %d\n", sizeof(char*));
    printf("Time Zone(sizeof long): %d\n", sizeof(time_zone));
    printf("float: %d\n", sizeof(float));
    printf("short: %d\n", sizeof(short));
    printf("double: %d\n", sizeof(double));

    return 0;
}
