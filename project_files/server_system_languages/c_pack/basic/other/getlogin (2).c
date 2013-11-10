#include<unistd.h>

main()
{
	printf("I am %s.\n",getlogin());
}