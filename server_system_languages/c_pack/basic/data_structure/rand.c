#include<stdlib.h>
#include<stdio.h>

main()
{
    int i,j;
    for(i=0;i<10;i++)
    {
        j=1+(int)(10.0*rand()/(RAND_MAX+1.0));
        printf("%d\n",j);
    }
}	
