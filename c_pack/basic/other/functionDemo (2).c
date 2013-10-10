#include<stdio.h>

int myabs(int x);

void main()
{
	int x;
	scanf("%d",&x);
	x = myabs(x);
	printf("%d\n",x);
}

int myabs(int x)
{
	return(x>0?x:-x);
}
