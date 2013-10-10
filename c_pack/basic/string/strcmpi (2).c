/*
函数名: strcmpi 
功  能: 将一个串中的一部分与另一个串比较, 不管大小写 
用  法: int strcmpi(char *str1, char *str2, unsigned maxlen); 
程序例:

#include <string.h> 
#include <stdio.h>

int main(void) 
{ 
   char *buf1 = "BBB", *buf2 = "bbb"; 
   int ptr;

   ptr = strcmpi(buf2, buf1);

   if (ptr > 0) 
      printf("buffer 2 is greater than buffer 1\n");

   if (ptr < 0) 
      printf("buffer 2 is less than buffer 1\n");

   if (ptr == 0) 
      printf("buffer 2 equals buffer 1\n");

   return 0; 
} 
*/  


#include <stdio.h>
#include <string.h>

void main()
  {
    printf( "%d\n", strcmpi( "AbCDEF", "abcdef" ) );
    printf( "%d\n", strcmpi( "abcdef", "ABC"    ) );
    printf( "%d\n", strcmpi( "abc",    "ABCdef" ) );
    printf( "%d\n", strcmpi( "Abcdef", "mnopqr" ) );
    printf( "%d\n", strcmpi( "Mnopqr", "abcdef" ) );
  } 
  
