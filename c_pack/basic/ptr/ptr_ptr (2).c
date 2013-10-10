    #include<stdio.h>
    
    int main()
    {
        int i, *pi, **dpi;
        pi = &i;
        dpi = &pi;
        **dpi = 100;
        printf("i:%d\n",i);
        return 0;
    }
