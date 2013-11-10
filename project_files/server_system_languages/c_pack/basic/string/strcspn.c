/*
函数名: strcspn 
功  能: 在串中查找第一个给定字符集内容的段 
用  法: int strcspn(char *str1, char *str2); 
程序例:
*/

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

int main(void) 
 { 
    char *string1 = "12345678 90"; 
    char *string2 = " "; 
    int length;

    length = strcspn(string1, string2); 
    printf("Character where strings intersect is at position %d\n", length);

    return 0; 
 } 
  
