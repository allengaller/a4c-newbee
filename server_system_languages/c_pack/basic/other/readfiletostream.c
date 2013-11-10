#include<stdio.h>

FILE *fp;
fp = fopen(name, mode);

fscanf(fp, "format string", variable list);
fprintf(fp, "format string", variable list);

fclose(fp);
