    #include<stdio.h>
    #include<string.h>
    
    int main()
    {
        const char *s1 = "Happy New Year!";
        const char *s2 = "Year";
        const char *s3 = "pye HwNa";

        char *p;
        p = strchr(s1, 'a');
        printf("在字符串s1中首次出现字母‘a’的位置是");

        p != NULL ? puts(p) : puts("无");//避免输出指向空的指针
        
        p = strrchr(s1, 'a');
        printf("在字符串s1中最后一次出现字母‘a’的位置是：");
        
        p != NULL ? puts(p) : puts("无");
              printf("字符串s1从首字符开始不包括字符串s2所含字符的分段长度是：%d\n"
                , strcspn(s1, s2));


    }
