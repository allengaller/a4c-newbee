
atof（将字符串转换成浮点型数）
相关函数
atoi，atol，strtod，strtol，strtoul
表头文件
#include <stdlib.h>
定义函数
double atof(const char *nptr);
函数说明
atof()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，而再遇到非数
字或字符串结束时('\0')才结束转换，并将结果返回。参数nptr字符串可包含正负号、小数点或E(e)来表示
指数部分，如123.456或123e-2。
返回值
返回转换后的浮点型数。
附加说明
atof()与使用strtod(nptr,(char**)NULL)结果相同。

范例

/* 将字符串a 与字符串b转换成数字后相加*/
#include<stdlib.h>
main()
{
    char *a=”-100.23”;
    char *b=”200e-2”;
    float c;
    c=atof(a)+atof(b);
    printf(“c=%.2f\n”,c);
}

执行

c=-98.23
　
================================================================================

atoi（将字符串转换成整型数）
相关函数
atof，atol，atrtod，strtol，strtoul
表头文件
#include<stdlib.h>
定义函数
int atoi(const char *nptr);
函数说明
atoi()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，而再遇到非数字或字符串结束时('\0')才结束转换，并将结果返回。
返回值
返回转换后的整型数。
附加说明
atoi()与使用strtol(nptr，(char**)NULL，10)；结果相同。

范例

/* 将字符串a 与字符串b转换成数字后相加*/
#include<stdlib.h>
mian()
{
    char a[]=”-100”;
    char b[]=”456”;
    int c;
    c=atoi(a)+atoi(b);
    printf(c=%d\n”,c);
}

执行

c=356
　
================================================================================

atol（将字符串转换成长整型数）
相关函数
atof，atoi，strtod，strtol，strtoul
表头文件
#include<stdlib.h>
定义函数
long atol(const char *nptr);
函数说明
atol()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，而再遇到非数字或字符串结束时('\0')才结束转换，并将结果返回。
返回值
返回转换后的长整型数。
附加说明
atol()与使用strtol(nptr,(char**)NULL,10)；结果相同。

范例

/*将字符串a与字符串b转换成数字后相加*/
#include<stdlib.h>
main()
{
    char a[]=”1000000000”;
    char b[]=” 234567890”;
    long c;
    c=atol(a)+atol(b);
    printf(“c=%d\n”,c);
}

执行

c=1234567890
　
================================================================================

gcvt（将浮点型数转换为字符串，取四舍五入）
相关函数
ecvt，fcvt，sprintf
表头文件
#include<stdlib.h>
定义函数
char *gcvt(double number，size_t ndigits，char *buf);
函数说明
gcvt()用来将参数number转换成ASCII码字符串，参数ndigits表示显示的位数。gcvt()与ecvt()和fcvt()不同的地方在于，gcvt()所转换后的字符串包含小数点或正负符号。若转换成功，转换后的字符串会放在参数buf指针所指的空间。
返回值
返回一字符串指针，此地址即为buf指针。
附加说明

范例

#include<stdlib.h>
main()
{
    double a=123.45;
    double b=-1234.56;
    char *ptr;
    int decpt,sign;
    gcvt(a,5,ptr);
    printf(“a value=%s\n”,ptr);
    ptr=gcvt(b,6,ptr);
    printf(“b value=%s\n”,ptr);
}

执行

a value=123.45
b value=-1234.56
　
================================================================================

strtod（将字符串转换成浮点数）
相关函数
atoi，atol，strtod，strtol，strtoul
表头文件
#include<stdlib.h>
定义函数
double strtod(const char *nptr,char **endptr);
函数说明
strtod()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，到出现非数字或字符串结束时('\0')才结束转换，并将结果返回。若endptr不为NULL，则会将遇到不合条件而终止的nptr中的字符指针由endptr传回。参数nptr字符串可包含正负号、小数点或E(e)来表示指数部分。如123.456或123e-2。
返回值
返回转换后的浮点型数。
附加说明
参考atof()。

范例

/*将字符串a，b，c 分别采用10，2，16 进制转换成数字*/
#include<stdlib.h>
mian()
{
    char a[]=”1000000000”;
    char b[]=”1000000000”;
    char c[]=”ffff”;
    printf(“a=%d\n”,strtod(a,NULL,10));
    printf(“b=%d\n”,strtod(b,NULL,2));
    printf(“c=%d\n”,strtod(c,NULL,16));
}

执行

a=1000000000
b=512
c=65535
　
================================================================================

strtol（将字符串转换成长整型数）
相关函数
atof，atoi，atol，strtod，strtoul
表头文件
#include<stdlib.h>
定义函数
long int strtol(const char *nptr,char **endptr,int base);
函数说明
strtol()会将参数nptr字符串根据参数base来转换成长整型数。参数base范围从2至36，或0。参数base代表采用的进制方式，如base值为10则采用10进制，若base值为16则采用16进制等。当base值为0时则是采用10进制做转换，但遇到如'0x'前置字符则会使用16进制做转换。一开始strtol()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，再遇到非数字或字符串结束时('\0')结束转换，并将结果返回。若参数endptr不为NULL，则会将遇到不合条件而终止的nptr中的字符指针由endptr返回。
返回值
返回转换后的长整型数，否则返回ERANGE并将错误代码存入errno中。
附加说明
ERANGE指定的转换字符串超出合法范围。

范例

/* 将字符串a，b，c 分别采用10，2，16进制转换成数字*/
#include<stdlib.h>
main()
{
    char a[]=”1000000000”;
    char b[]=”1000000000”;
    char c[]=”ffff”;
    printf(“a=%d\n”,strtol(a,NULL,10));
    printf(“b=%d\n”,strtol(b,NULL,2));
    printf(“c=%d\n”,strtol(c,NULL,16));
}

执行

a=1000000000
b=512
c=65535
　
================================================================================

strtoul（将字符串转换成无符号长整型数）
相关函数
atof，atoi，atol，strtod，strtol
表头文件
#include<stdlib.h>
定义函数
unsigned long int strtoul(const char *nptr,char **endptr,int base);
函数说明
strtoul()会将参数nptr字符串根据参数base来转换成无符号的长整型数。参数base范围从2至36，或0。参数base代表采用的进制方式，如base值为10则采用10进制，若base值为16则采用16进制数等。当base值为0时则是采用10进制做转换，但遇到如'0x'前置字符则会使用16进制做转换。一开始strtoul()会扫描参数nptr字符串，跳过前面的空格字符串，直到遇上数字或正负符号才开始做转换，再遇到非数字或字符串结束时('\0')结束转换，并将结果返回。若参数endptr不为NULL，则会将遇到不合条件而终止的nptr中的字符指针由endptr返回。
返回值
返回转换后的长整型数，否则返回ERANGE并将错误代码存入errno中。
附加说明
ERANGE指定的转换字符串超出合法范围。
范例
参考strtol()
　
================================================================================

toascii（将整型数转换成合法的ASCII 码字符）
相关函数
isascii，toupper，tolower
表头文件
#include<ctype.h>
定义函数
int toascii(int c)
函数说明
toascii()会将参数c转换成7位的unsigned char值，第八位则会被清除，此字符即会被转成ASCII码字符。
返回值
将转换成功的ASCII码字符值返回。

范例

#include<stdlib.h>
main()
{
    int a=217;
    char b;
    printf(“before toascii () : a value =%d(%c)\n”,a,a);
    b=toascii(a);
    printf(“after toascii() : a value =%d(%c)\n”,b,b);
}

执行

before toascii() : a value =217()
after toascii() : a value =89(Y)
　
================================================================================

tolower（将大写字母转换成小写字母）
相关函数
isalpha，toupper
表头文件
#include<stdlib.h>
定义函数
int tolower(int c);
函数说明
若参数c为大写字母则将该对应的小写字母返回。
返回值
返回转换后的小写字母，若不须转换则将参数c值返回。
附加说明

范例

/* 将s字符串内的大写字母转换成小写字母*/
#include<ctype.h>
main()
{
    char s[]=”aBcDeFgH12345;!#$”;
    int i;
    printf(“before tolower() : %s\n”,s);
    for(i=0;I<sizeof(s);i++)
        s[i]=tolower(s[i]);
        printf(“after tolower() : %s\n”,s);
}

执行

before tolower() : aBcDeFgH12345;!#$
after tolower() : abcdefgh12345;!#$
　
================================================================================

toupper（将小写字母转换成大写字母）
相关函数
isalpha，tolower
表头文件
#include<ctype.h>
定义函数
int toupper(int c);
函数说明
若参数c为小写字母则将该对映的大写字母返回。
返回值
返回转换后的大写字母，若不须转换则将参数c值返回。
附加说明

范例

/* 将s字符串内的小写字母转换成大写字母*/
#include<ctype.h>
main()
{
    char s[]=”aBcDeFgH12345;!#$”;
    int i;
    printf(“before toupper() : %s\n”,s);
    for(i=0;I<sizeof(s);i++)
        s[i]=toupper(s[i]);
        printf(“after toupper() : %s\n”,s);
}

执行

before toupper() : aBcDeFgH12345;!#$
after toupper() : ABCDEFGH12345;!#$
　
================================================================================

