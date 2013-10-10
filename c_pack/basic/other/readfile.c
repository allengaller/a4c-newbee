//Write a program to print stuff to a file reading the number of time
//for an other file

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void writefile(char *);

int main() 
{
        int N;
	FILE *inf;
	int i;

	inf = fopen("infile.txt", "r");

	/* Now let us read the number from a file */
	fscanf(inf, "%d", &N);
	
	for(i = 0; i < N; i++) 
	        writefile("WWW");

	printf("\n");
	fclose(inf);
	return(0);
}

void writefile(char *str) 
{
        FILE *outf;
	int i;

	outf = fopen("outfile.txt", "a");
	
	/* Now let us write to the file */
	fprintf(outf, "%s", str);
	
	fclose(outf);
}

