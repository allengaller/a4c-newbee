    #include<stdio.h>

    int main()
    {
        const char *c[4] = {
            "China",
            "USA",
            "Russia",
            "Japan"
        };
        int i;
        for(i = 0; i < 4; i++)
            puts(*(c + i));
        return 0;
    }
