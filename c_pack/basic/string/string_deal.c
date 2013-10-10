    #include<stdio.h>
    #include<string.h>
    #define LENGTH 20

    int main()
    {
        char a[LENGTH];
        const char *s = "ABCDEFG";
        strcpy(a, s);
        puts(a);

        strncpy(a, s, 4);
        puts(a);

        strcat(a,s);
        puts(a);

        strcat(a, s);
        puts(a);

        strncat(a, s, 4);
        puts(a);

        const char *s1 = "Happy New Year!";
        const char *s2 = "Happy New Year!";
        const char *s3 = "Happy Holiday!";

        printf("%d, %d, %d\n", strcmp(s1, s2), strcmp(s1, s3), strcmp(s2, s3));
        printf("%d ,%d, %d\n", strncmp(s1, s2, 6), strncmp(s1, s3, 7), strncmp(s3, s2, 7));

        return 0;
    }
