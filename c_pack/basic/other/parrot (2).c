#include<stdio.h>
#define MAXLINE 20

int main()
{
	char line[MAXLINE];

	while(fgets(line, MAXLINE, stdin) != NULL && line[0] != '\n')
	{
		fputs(line, stdout);
		printf("line: %s\n", line);
	}

	return 0;
}
