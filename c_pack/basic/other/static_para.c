    #include<stdio.h>
    
    void func()
    {
        static int x = 100;
        printf("x:%d\n",x);
        x += 100;
    }
    
    int main()
    {
        func();
        func();
        return 0;
    }
