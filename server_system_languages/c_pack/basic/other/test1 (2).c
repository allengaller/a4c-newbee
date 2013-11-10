#include<stdio.h>
#include<string.h>

main()
{
    char i[10];
    char j[10] = "abc";
    strcpy(i, j);
    printf("%s\n", i);

    char a[10];
    printf("%s\n", a);
    strcpy(a, "AAA");
    printf("%s\n", a);
}
