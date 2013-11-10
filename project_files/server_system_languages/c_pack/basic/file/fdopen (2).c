#include<stdio.h>
#include<stdio.h>

main()
{
    FILE * fp = fdopen(0,"w+");
    fprintf(fp,"%s\n","hello!");
    fclose(fp);
}
