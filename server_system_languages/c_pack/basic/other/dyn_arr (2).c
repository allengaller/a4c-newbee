// 为数组动态分配存储空间
#include<stdio.h>
#include<stdlib.h>//为了给malloc() free()函数提供原型

int main()
{
	double * ptd;
	int max;
	int number;
	int i = 0;
	
	puts("What is the maximun number of entries?\n");
	scanf("%d",&max);
	ptd = (double *)malloc(max * sizeof(double));
	if(ptd==NULL)
	{
		puts("Memory allocation failed. Goodbye.\n");
		exit(EXIT_FAILURE);
	}
	
	//ptd现在指向有max个元素的数组
	puts("Enter the values (q to quit): ");
	while(i<max&&scanf("%1f",&ptd[i])==1)
		++i;
	printf("Here are your %d enteries: \n",number = i);
	for(i = 0; i< number; i++)
	{
		printf("%7.2f",ptd[i]);
		if(i%7==6)
			putchar('\n');
	}
	if(i % 7 != 0)
		putchar('\n');
	puts("Done.\n");
	free(ptd);
	return 0;
}
