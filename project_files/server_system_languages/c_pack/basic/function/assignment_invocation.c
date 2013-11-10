    #include<stdio.h>
    
    void func(int a, int *b)
    {
        a = 199;
        *b = 299;
    }

    int main()
    {
        int a = 0, b = 0;
        printf("a = %d, b = %d\n", a, b);
        func(a, &b);
        printf("a = %d, b = %d\n", a, b);
        return 0;
    }
