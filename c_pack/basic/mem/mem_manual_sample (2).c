#include<string.h>
#include<stdio.h>

main()
{
	char s[30];
	memset(s, 'A', sizeof(s));
	s[29] = '\0';
	printf("s:%s\n", s);
}
