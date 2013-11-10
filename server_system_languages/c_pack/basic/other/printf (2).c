#include<stdio.h>

int main()
{
	char c = 'a';
	int i = 1234;
	float f = 12.123456;
	double d = 12.5;

	printf("%d %o %x\n",i,i,i);//对于int:d是十进制，o是八进制，x是十六进制
	printf("%c %d\n",c,c);     //对于char:c是字符变量一般输出，d是ANSI值
	printf("%s\n", "hello");   //对于字符串：s输出
	printf("%f %e %g\n",f,f,f);//对于浮点型变量：f是一 般浮点形式输出，e是小数部分最多只能输出6位，最后一位6是四舍五入得到的，g是小数部分只能保留4位，最后一位四舍五入。
	printf("12345678901234567890\n");
	printf("%5c%5d%10.5f\n",c,i,f,d);//dd.dd格式输出
	printf("12345678901234567890\n");
	printf("%-5c%-5d%-10.5f%-10.5f\n",c,i,f,d);//-dd.dd格式输出
}
