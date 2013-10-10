#include<stdio.h>
main()
{
    FILE * fp;
    fp=fopen("/etc/passwd" , "r");
    fp=freopen("/etc/group" , "r" , fp);
    fclose(fp);
}
