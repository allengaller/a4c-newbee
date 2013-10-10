#include<stdio.h>
#include<stdlib.h>  //for exit()

int main()
{
	int ch;
	FILE * fp;
	char fname[50];
	
	printf("Enter the name of the file: ");
	scanf("%s", fname);
	fp = fopen(fname, "r"); //打开文件以供读取
	if(fp == NULL)
	{
		printf("Failed to open file. \n");
		exit(1);
	}
	//getc(fp)从打开的文件中获取一个字符
	while((ch = getc(fp))!= EOF)
	{
		putchar(ch);
	}
	fclose(fp);
	return 0;
}
