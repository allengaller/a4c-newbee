#include<stdlib.h>

main()
{
	char a[]="-100";
	char b[]="  456";
	int c;
	c = atoi(a) + atoi(b);
	printf("c = %d\n",c);
}
