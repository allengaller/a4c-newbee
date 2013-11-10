#include<stdio.h>

int main()
{
	FILE *fp;
	fp = fopen("/home/allengaller/Desktop/abc.txt","r");
	if(fp != NULL)
		puts("打开文件成功！");
	else{
		perror("打开文件");
		return 1;
	}
	if(fclose(fp) != -1)
		puts(" 关闭文件成功！");
	else{
		perror("关闭文件");
		return 1;	
	}
	return 0;
}
