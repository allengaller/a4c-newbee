#include<stdlib.h>
#include<stdio.h>

void my_exit(int status,void *arg)
{
    printf("before exit()!\n");
    printf("exit(%d)\n",status);
    printf("arg = %s\n",(char*)arg);
}

main()
{
    char * str = "test";
    on_exit(my_exit,(void *)str);
    exit(1234);
}
