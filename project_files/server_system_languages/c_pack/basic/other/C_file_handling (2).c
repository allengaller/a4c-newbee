#include <stdio.h>

int main() {
 char test[]="a teststring\0";
 FILE *f;											// create a new filepointer
 if((f=fopen("file","w"))==NULL) {			// open a file
  printf("could not open file");				// print an error
  exit(1);
 }
 fputc(test[0],f);
 fputs(test,f);
 fprintf(f,"\n%ch%c%c %c%c %s\n",test[2],test[9],test[4],test[9],test[4],test);
 fclose(f);
 if((f=fopen("file","r"))==NULL) {			// open a file
  printf("could not open file");				// print an error
  exit(1);
 }
 char ch;
 ch=fgetc(f);
 printf("%c\n",ch);
 fgets(test,20,f);
 printf("%s",test);
 while(!feof(f)) {
  test[0]='\0';
  fscanf(f,"%s",test);
  printf("%s ",test);
 };
 fclose(f);
 return 1;
}
