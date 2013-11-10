#include<stdlib.h>
main()
{
    char *p;
    if((p = getenv("USER")))
        printf("USER=%s\n",p);
}

