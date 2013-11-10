/*
函数名: strupr 
功  能: 将串中的小写字母转换为大写字母 
用  法: char *strupr(char *str); 
程序例:
*/


#include <stdio.h> 
#include <string.h>

int main(void) 
{ 
   char *string = "abcdefghijklmnopqrstuvwxyz"; 
   char *ptr;

   /* converts string to upper case characters */ 
   ptr = strupr(string); 
   printf("%s\n", ptr); 
   return 0; 
} 
