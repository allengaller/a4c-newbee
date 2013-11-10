#include<stdio.h>

int main()
{
	FILE *fp;
	int i;
	
	fp = fopen("foo.dat", "w");
	
	fprintf(fp, "\nSample\n");
	
	for(i = 1; i<=10;i++)
	{
		fprintf(fp, "i = %d\n", i);
	}	
	fclose(fp);
	return 0;
}
