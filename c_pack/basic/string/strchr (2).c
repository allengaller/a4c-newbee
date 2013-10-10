/*
函数名: strchr 
功  能: 在一个串中查找给定字符的第一个匹配之处\ 
用  法: char *strchr(char *str, char c); 
程序例:
*/

#include <string.h> 
#include <stdio.h>

int main(void) 
 { 
    char string[15]; 
    char *ptr, c = 'r';

    strcpy(string, "This is a string"); 
    ptr = strchr(string, c); 
    if (ptr) 
       printf("The character %c is at position: %d\n", c, ptr-string); 
    else 
       printf("The character was not found\n"); 
    return 0; 
 } 
  
