/*
#include<stdio.h>

int main()
{
	int ch;	//int来控制EOF
	FILE *fp;
	fp = fopen("whattofuck.txt", "r");
	ch = getc(fp);	//获得初始输入
	while(ch!=EOF)
	{
		putchar(ch);	//处理输入
		ch = getc(fp);	//获得下一个输入
	}
	return 1;
}
*/

#include<stdio.h>

int main()
{
	int ch;	//int来控制EOF
	FILE * fp;
	fp = fopen("whattofuck.txt","r");
	while((ch = getc(fp))!= EOF)
	{
		ch = getc(fp);
		putchar(ch);
	}	
	return 1;
}
