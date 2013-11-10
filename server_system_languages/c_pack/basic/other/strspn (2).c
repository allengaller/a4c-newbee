#include<string.h>
#include<stdio.h>

main()
{
    char* str = "<Msg>Linux is powerful.</Msg>*&^*&^@";
    char* t1 = "<Msg>";
    char* t2 = "is";
    char* t3 = "</Msg>";
    
    printf("%d\n",strspn(str,t1));
    printf("%d\n",strspn(str,t2));
    printf("%d\n",strspn(str,t3));
}
