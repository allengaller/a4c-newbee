#include<stdio.h>
#include<string.h>
int main()
{
	char *s = "Hello aaa";
	char d1[20], d2[20];
	strcpy(d1, s);
	strncpy(d2,s,sizeof(s));
	printf("d1:%s\n", d1);
	printf("d2:%s\n", d2);
	return 1;
}
