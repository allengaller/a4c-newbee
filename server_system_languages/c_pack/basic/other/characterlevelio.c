/*
#include<stdio.h>

int main()
{
    int i, nc;
	
    nc = 0;
    i = getchar();
   
    while (i != EOF) 
   {
	nc = nc + 1;
	i = getchar();
    }
    printf("Number of characters in file = %d\n", nc);
	return 0;
}
*/
/*
#include<stdio.h>
int main()
{
    int c, nc = 0;

    while ( (c = getchar()) != EOF ) 
	nc++;
    printf("Number of characters in file = %d\n", nc);
    return 0;
}*/


#include<stdio.h>

int main()
{
    int c, nc = 0, nl = 0;

    while ((c = getchar()) != EOF)
    {
	nc++;
	if (c == '\n') nl++;
    }

    printf("Number of characters = %d, number of lines = %d\n",nc, nl);
	return 1;
}



