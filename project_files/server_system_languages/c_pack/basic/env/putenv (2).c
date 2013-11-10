#include<stdlib.h>
#include<stdio.h>

main()
{
    char *p;
    if((p = getenv("USER"))) {
        printf("USER =%s\n",p);
        putenv("USER=test");
        printf("getenv= %s\n",getenv("USER"));
    }
}

