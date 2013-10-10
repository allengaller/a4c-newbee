#include <string.h>

int main()
{
    char s[] = "qwjhvhjvhsd--@sadcsac";
    char *delim = "--@";
    char *output;
    char *final; 
    
    printf("strtor returns : %s\n", strtok(s, delim));
    printf("s : %s\n", s);
    printf("delim : %s\n", delim);
    memcpy(final, s, sizeof(s));
    //strcpy(final, s);
    
    //printf("output = strtok(NULL, delim) returns : %s\n", output = strtok(NULL, delim));
    
    while(output = strtok(NULL, delim))
        printf("output: %s\n", output);
    
    return 0;
}
