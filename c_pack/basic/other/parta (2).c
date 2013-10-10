#include<stdio.h>

void report_count();
void accumulate(int k);

int count = 0;//文件作用域， 外部链接

int main(void)
{
	int value; //自动变量
	register int i; //寄存器变量
	
	printf("Enter a positive integer (0 to quit): ");
	while(scanf("%d",&value)==1&&value>0)
	{
		++count;//使用文件作用域变量
		for(i=value;i>=0;i--)
			accumulate(i);
		printf("Enter a positive integer (0 to quit):");
	}
	report_count();
	return 0;
}

void report_count()
{
	printf("Loop executed %d times.\n",count);
}



extern int count;//引用声明， 外部链接

static int total = 0;//静态定义， 内部链接

void accumulate(int k); //原型
void accumulate(int k)  //k具有代码块作用域， 空链接
{
	static int subtotal = 0;//静态， 空链接

	if(k <= 0)
	{
		printf("loop cycle: %d\n",count);
		printf("subtotal: %d; total: %d\n",subtotal, total);
		subtotal = 0;
	}
	else
	{
		subtotal += k;
		total += k;
	};
}
