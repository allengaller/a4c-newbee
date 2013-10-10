#include<stdio.h>

#define SIZE 65536
#define LENGTH 1024

int main()
{
	char buf[SIZE] = {0};
	FILE *fp;
	fp = fopen("/usr/include/gnu-versions.h","r");
	if(fp != NULL)
	{
		if(fread(buf, LENGTH, SIZE / LENGTH, fp) >= 0)
			puts("读取文件成功");
		else{
			perror("读取文件失败");
			return 1;		
		}
	}
	else
		perror;
}
