#include<stdio.h>

main()
{
    FILE * stream;
    long offset;
    fpos_t pos;
    stream=fopen("/etc/passwd" , "r");
    fseek(stream , 5 , SEEK_SET);
    printf(" offset = %d\n" , ftell(stream));
    rewind(stream);
    fgetpos(stream , &pos);
    printf("offset = %d\n" , pos);
    pos = 10;
    fsetpos(stream,&pos);
    printf("offset = %d\n" , ftell(stream));
    fclose(stream);
}
