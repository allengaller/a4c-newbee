#include<stdio.h>
main()
{
    FILE * fp;
    char a[26] = "abcdefghijklmnopqrstuvwxyz";
    int i;
    fp= fopen("noexist" , "w");
    for(i=0;i<26;i++)
        fputc(a[i],fp);
    fclose(fp);
}
