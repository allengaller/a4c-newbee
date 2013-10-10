#include<stdio.h>

int units = 0;  //一个外部变量

void critic(void);

int main(void)
{
	extern int units;//可选的二次声明，告诉编译器在该函数中用到的units都是指同一个在函数外部，甚至是文件外部定义的变量
	printf("How many balls are there in the bottle?\n");
	scanf("%d",&units);
	while(units != 56)
		critic();
	printf("You must have looked it up!\n");
	return 0;
}

void critic(void)
{
	printf("No luck , chummy. Try again.\n");
	scanf("%d",&units);
}
