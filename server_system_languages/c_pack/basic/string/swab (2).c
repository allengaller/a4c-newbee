/*
函数名: swab 
功  能: 交换字节 
用  法: void swab (char *from, char *to, int nbytes); 
程序例:
*/
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>

char source[15] = "rFna koBlrna d"; 
char target[15];

int main(void) 
{ 
   swab(source, target, strlen(source)); 
   printf("This is target: %s\n", target); 
   return 0; 
}
