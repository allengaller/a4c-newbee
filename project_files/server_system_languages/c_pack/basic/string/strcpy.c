/*
函数名: strcpy 
功  能: 串拷贝 
用  法: char *strcpy(char *str1, char *str2); 
程序例:
*/

#include <stdio.h> 
#include <string.h>

int main(void) 
 { 
    char string[10]; 
    char *str1 = "abcdefghi";

    strcpy(string, str1); 
    printf("%s\n", string); 
    return 0; 
 } 
