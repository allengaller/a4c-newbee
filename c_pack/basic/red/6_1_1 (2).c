#include<stdio.h>

int main()
{
    printf("字符型char字长：%d byte\n", sizeof(char));
    printf("整型int字长：%d byte\n", sizeof(int));
    printf("长整型long字长：%d byte\n", sizeof(long));
    printf("单精度浮点float字长：%d byte\n", sizeof(float));
    printf("双精度浮点double字长：%d byte\n", sizeof(double));
    
    putchar('A');               //单引号中的是字符常量
    printf("\nMick Scott!\n");  //双引号中的是字符串常量
    int a = 500.22;             //赋值符号后边的是数值常量
    printf("a=%d\n",a);
    
    const int dog_count = 65;
    //dog_count ++;
    //error: increment of read-only variable ‘dog_count’
    printf("\ndog_count = %d\n",dog_count);
    
    enum weekday{
        MON = 1,
        TUE,
        WED,
        THU,
        FRI,
        SAT,
        SUN
    };
    printf("\nSUN = %d\n", SUN);
    
    char x = 0x6D;
    printf("\nx's value is %c\n", x);
    
    char c1, c2, c3;
    c1 = 357;
    c2 = -251;
    c3 = 'm' + 256;
    //6_1_1.c:36: warning: overflow in implicit constant conversion
    //6_1_1.c:37: warning: overflow in implicit constant conversion
    //6_1_1.c:38: warning: overflow in implicit constant conversion
    printf("%d, %d, %d\n", c1, c2, c3);
    
    int john = 1, b = 7;
    a > b ? b ++ : b--;
    
    
    return 0;
}
