#include<stdio.h>

main()
{
    FILE * fp;
    fp=fopen("noexist" , "a+");
    if(fp == NULL) return;
    fclose(fp);
}
