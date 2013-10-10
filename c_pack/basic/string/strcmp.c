/*
函数名: strcmp 
功  能: 串比较 
用  法: int strcmp(char *str1, char *str2); 
看Asic码，str1>str2，返回值 > 0；两串相等，返回0
程序例:
*/

#include <string.h> 
#include <stdio.h>

int main(void) 
 { 
    char *buf1 = "aaa", *buf2 = "zzz", *buf3 = "ccc"; 
    int ptr;

    ptr = strcmp(buf2, buf1); 
    if (ptr > 0) 
       printf("buffer 2 is greater than buffer 1\n"); 
    else 
       printf("buffer 2 is less than buffer 1\n");

    ptr = strcmp(buf2, buf3); 
    if (ptr > 0) 
       printf("buffer 2 is greater than buffer 3\n"); 
    else 
       printf("buffer 2 is less than buffer 3\n");

    return 0; 
 } 
 

