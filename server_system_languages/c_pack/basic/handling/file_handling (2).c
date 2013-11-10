C File Handling

Written by:	noimnot
Published by:	Nightscript
Published on:	2005-11-14 

With C, everything from an on-disc file to a printer is a file. To handle files efficiently, the "FILE *" datatype has been introduced.

File pointers (FILE *) are defined within <stdio.h>, which means you have to add #include <stdio.h> at the beginning of each program. 

Opening a File 

		     FILE* f; // create a new file pointer 
		     if((f=fopen("file","w"))==NULL) { // open a file 
		      printf("could not open file"); // print an error 
		       exit(1); 
		       } 


The function fopen() is defined as FILE *fopen(const char *filename,const char *mode);. On success it returns a valid FILE * (file pointer) or NULL if the file, as indicated by the filename, is not found. It takes the filename as first, and as a second argument, one of the following modes: 

		       r	 -	open a file in read-mode, set the pointer to the beginning of the file. 
		       w	 -	open a file in write-mode, set the pointer to the beginning of the file. 
		       a	 -	open a file in write-mode, set the pointer to the end of the file. 
		       rb	 -	open a binary-file in read-mode, set the pointer to the beginning of the file. 
		       wb	 -	open a binary-file in write-mode, set the pointer to the beginning of the file. 
		       ab	 -	open a binary-file in write-mode, set the pointer to the end of the file. 
		       r+	 -	open a file in read/write-mode, if the file does not exist, it will not be created. 
		       w+	 -	open a file in read/write-mode, set the pointer to the beginning of the file. 
		       a+	 -	open a file in read/append mode. 
		       r+b -	open a binary-file in read/write-mode, if the file does not exist, it will not be created. 
		       w+b -	open a binary-file in read/write-mode, set the pointer to the beginning of the file. 
		       a+b -	open a binary-file in read/append mode. 


		       The maximum number of files that can be opened simultaneously is defined as FOPEN_MAX. 

		       Closing a file is done using the fclose() function, which is defined as int fclose(FILE *fp);. 

		       fclose(f);	 // close the filepointer 


		       Writing to files can be done in various ways: 

		       putc()	-	like fputc() 
		       fputc()	-	int fputc (int character, FILE * stream); - write a character to a file 
		       fputs()	-	int fputs (const char * string , FILE * stream); - write a string to a file 
		       fprintf()-	int fprintf (FILE * stream , const char * format
		       [ , argument , ...] ); -	works like printf() except that it writes to a file instead of
		       STDOUT. 


		       just like reading from files: 

		       getc() -	like fgetc() 
		       fgetc() - int fgetc (FILE * stream); - write a character to a file 
		       fgets() - char * fgets (char * string , int num , FILE * stream); - write a string to a file 
		       fscanf() - int fscanf ( FILE * stream , const char * format
		       [ , argument , ...] ); - works like scanf() except that it reads from a file instead of STDIN 


		       an example on how to use these functions: 

		       [code] 
		       #include <stdio.h> 

		       int main() { 
		       char test[]="a teststring
