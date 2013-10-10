    #include<stdio.h>
    
    int main()
    {
        auto int x = 100;
        if(x < 150)
        {
            auto int x = 200;
            printf("x:%d\n", x);
        }
        return 0;
    }
