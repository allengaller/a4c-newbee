#include<stdio.h>

main()
{
	float a,b,c,temp;
	printf("Input 3 numbers:\n");
	scanf("%f,%f,%f",&a,&b,&c);
	printf("The number is:%f,%f,%f\n",a,b,c);

	if(a>b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if(a>c)
	{
		temp = a;
		a = c;
		c = temp;
	}
	if(b>c)
	{
		temp = b;
		b = c;
		c = temp;
	}
	
	printf("Afer sortting:%f,%f,%f\n",a,b,c);
}
