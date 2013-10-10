/* 显示错误代码0 至9 的错误原因描述*/
#include<string.h>
#include<stdio.h>

main()
{
    int i;
    for(i=0;i<10;i++)
        printf("%d : %s\n" , i , strerror(i));
}

