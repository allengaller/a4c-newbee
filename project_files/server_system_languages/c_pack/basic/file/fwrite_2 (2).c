#include<stdio.h>
#define set_s (x,y) { \
    strcoy(s[x].name,y);\
    s[x].size=strlen(y);}
#define nmemb 3

struct test
{
    char name[20];
    int size;
}s[nmemb];

main()
{
    FILE * stream;
    set_s(0 , "Linux!");
    set_s(1 , "FreeBSD!");
    set_s(2 , "Windows2000.");
    stream = fopen("/tmp/fwrite" , "w");
    fwrite(s , sizeof(struct test) , nmemb , stream);
    fclose(stream);
}
