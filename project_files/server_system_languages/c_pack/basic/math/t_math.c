　



abs（计算整型数的绝对值）
相关函数
labs, fabs
表头文件
#include<stdlib.h>
定义函数
int abs (int j)
函数说明
abs()用来计算参数j的绝对值，然后将结果返回。
返回值
返回参数j的绝对值结果。
范例
#ingclude <stdlib.h>
main(){
int ansert;
answer = abs(-12);
printf("|-12| = %d\n", answer);
}
执行
|-12| = 12
　



acos（取反余弦函数数值）
相关函数
asin , atan , atan2 , cos , sin , tan
表头文件
#include <math.h>
定义函数
double acos (double x);
函数说明
acos()用来计算参数x的反余弦值，然后将结果返回。参数x范围为－1至1之间，超过此范围则会失败。
返回值
返回0至PI之间的计算结果，单位为弧度，在函数库中角度均以弧度来表示。
错误代码
EDOM参数x超出范围。
附加说明
使用GCC编译时请加入－lm。
范例
#include <math.h>
main (){
double angle;
angle = acos(0.5);
printf("angle = %f\n", angle);
}
执行
angle = 1.047198
　



asin（取反正弦函数值）
相关函数
acos , atan , atan2 , cos , sin , tan
表头文件
#include <math.h>
定义函数
double asin (double x)
函数说明
asin()用来计算参数x的反正弦值，然后将结果返回。参数x范围为－1至1之间，超过此范围则会失败。
返回值
返回－PI/2之PI/2之间的计算结果。
错误代码
EDOM参数x超出范围
附加说明
使用GCC编译时请加入－lm
范例
#include<math.h>
main()
{
double angle;
angle = asin (0.5);
printf("angle = %f\n",angle);
}
执行
angle = 0.523599
　



atan（取反正切函数值）
相关函数
acos，asin，atan2，cos，sin，tan
表头文件
#include<math.h>
定义函数
double atan(double x);
函数说明
atan()用来计算参数x的反正切值，然后将结果返回。
返回值
返回-PI/2至PI/2之间的计算结果。
附加说明
使用GCC编译时请加入-lm
范例
#include<math.h>
main()
{
double angle;
angle =atan(1);
printf("angle = %f\n",angle);
}
执行
angle = 1.570796
　



atan2（取得反正切函数值）
相关函数
acos，asin，atan，cos，sin，tan
表头文件
#include<math.h>
定义函数
double atan2(double y,double x);
函数说明
atan2()用来计算参数y/x的反正切值，然后将结果返回。
返回值
返回-PI/2 至PI/2 之间的计算结果。
附加说明
使用GCC编译时请加入-lm。
范例
#include<math.h>
main()
{
double angle;
angle = atan2(1,2);
printf("angle = %f\n", angle);
}
执行
angle = 0.463648
　



ceil（取不小于参数的最小整型数）
相关函数
fabs
表头文件
#include <math.h>
定义函数
double ceil (double x);
函数说明
ceil()会返回不小于参数x的最小整数值，结果以double形态返回。
返回值
返回不小于参数x的最小整数值。
附加说明
使用GCC编译时请加入-lm。
范例
#include<math.h>
main()
{
double value[ ]={4.8,1.12,-2.2,0};
int i;
for (i=0;value[i]!=0;i++)
printf("%f=>%f\n",value[i],ceil(value[i]));
}
执行
4.800000=>5.000000
1.120000=>2.000000
-2.200000=>-2.000000
　



cos（取余玄函数值）
相关函数
acos，asin，atan，atan2，sin，tan
表头文件
#include<math.h>
定义函数
double cos(double x);
函数说明
cos()用来计算参数x 的余玄值，然后将结果返回。
返回值
返回-1至1之间的计算结果。
附加说明
使用GCC编译时请加入-lm。
范例
#include<math.h>
main()
{
double answer = cos(0.5);
printf("cos (0.5) = %f\n",answer);
}
执行
cos(0.5) = 0.877583
　



cosh（取双曲线余玄函数值）
相关函数
sinh，tanh
表头文件
#include<math.h>
定义函数
double cosh(double x);
函数说明
cosh()用来计算参数x的双曲线余玄值，然后将结果返回。数学定义式为:(exp(x)+exp(-x))/2。
返回值
返回参数x的双曲线余玄值。
附加说明
使用GCC编译时请加入-lm。
范例
#include<math.h>
main()
{
double answer = cosh(0.5);
printf("cosh(0.5) = %f\n",answer);
}
执行
cosh(0.5) = 1.127626
　



exp（计算指数）
相关函数
log，log10，pow
表头文件
#include<math.h>
定义函数
double exp(double x);
函数说明
exp()用来计算以e为底的x次方值，即ex值，然后将结果返回。
返回值
返回e的x次方计算结果。
附加说明
使用GCC编译时请加入-lm。
范例
#include<math.h>
main()
{
double answer;
answer = exp (10);
printf("e^10 =%f\n", answer);
}
执行
e^10 = 22026.465795
　



frexp（将浮点型数分为底数与指数）
相关函数
ldexp，modf
表头文件
#include<math.h>
定义函数
double frexp( double x, int *exp);
函数说明
frexp()用来将参数x 的浮点型数切割成底数和指数。底数部分直接返回，指数部分则借参数exp 指针返回，将返回值乘以2 的exp次方即为x的值。
返回值
返回参数x的底数部分，指数部分则存于exp指针所指的地址。
附加说明
使用GCC编译时请加入-lm。
范例
#include <math.h>
main()
{
int exp;
double fraction;
fraction = frexp (1024,&exp);
printf("exp = %d\n",exp);
printf("fraction = %f\n", fraction);
}
执行
exp = 11
fraction = 0.500000 /* 0.5*(2^11)=1024*/
　



ldexp（计算2的次方值）
相关函数
frexp
表头文件
#include<math.h>
定义函数
double ldexp(double x,int exp);
函数说明
ldexp()用来将参数x乘上2的exp次方值，即x*2exp。
返回值
返回计算结果。
附加说明
使用GCC编译时请加入-lm。
范例:
/* 计算3*(2^2)＝12 */
#include<math.h>
main()
{
int exp;
double x,answer;
answer = ldexp(3,2);
printf("3*2^(2) = %f\n",answer);
}
执行
3*2^(2) = 12.000000
　



log（计算以e 为底的对数值）
相关函数
exp，log10，pow
表头文件
#include <math.h>
定义函数
double log (double x);
函数说明
log（）用来计算以e为底的x 对数值，然后将结果返回。
返回值
返回参数x的自然对数值。
错误代码
EDOM 参数x为负数，ERANGE 参数x为零值，零的对数值无定义。
附加说明
使用GCC编译时请加入-lm。
范例
#include<math.h>
main()
{
double answer;
answer = log (100);
printf("log(100) = %f\n",answer);
}
执行
log(100) = 4.605170
　



log10（计算以10 为底的对数值）
相关函数
exp，log，pow
表头文件
#include<math.h>
定义函数
double log10(double x);
函数说明
log10()用来计算以10为底的x对数值，然后将结果返回。
返回值
返回参数x以10为底的对数值。
错误代码
EDOM参数x为负数。RANGE参数x为零值，零的对数值无定义。
附加说明
使用GCC编译时请加入-lm。
范例
#include<math.h>
main()
{
double answer;
answer = log10(100);
printf("log10(100) = %f\n",answer);
}
执行
log10(100) = 2.000000
　



pow（计算次方值）
相关函数
exp，log，log10
表头文件
#include<math.h>
定义函数
double pow(double x,double y);
函数说明
pow()用来计算以x为底的y次方值，即xy值，然后将结果返回。
返回值
返回x的y次方计算结果。
错误代码
EDOM 参数x为负数且参数y不是整数。
附加说明
使用GCC编译时请加入-lm。
范例
#include <math.h>
main()
{
double answer;
answer =pow(2,10);
printf("2^10 = %f\n", answer);
}
执行
2^10 = 1024.000000
　



sin（取正玄函数值）
相关函数
acos，asin，atan，atan2，cos，tan
表头文件
#include<math.h>
定义函数
double sin(double x);
函数说明
sin（）用来计算参数x的正玄值，然后将结果返回。
返回值
返回-1 至1之间的计算结果。
附加说明
使用GCC编译时请加入-lm。
范例
#include<math.h>
main()
{
double answer = sin (0.5);
printf("sin(0.5) = %f\n",answer);
}
执行
sin(0.5) = 0.479426
　



sinh（取双曲线正玄函数值）
相关函数
cosh，tanh
表头文件
#include<math.h>
定义函数
double sinh( double x);
函数说明
sinh()用来计算参数x的双曲线正玄值，然后将结果返回。数学定义式为:(exp(x)-exp(-x))/2。
返回值
返回参数x的双曲线正玄值。
附加说明
使用GCC编译时请加入-lm。
范例
#include<math.h>
main()
{
double answer = sinh (0.5);
printf("sinh(0.5) = %f\n",answer);
}
执行
sinh(0.5) = 0.521095
　



sqrt（计算平方根值）
相关函数
hypotq
表头文件
#include<math.h>
定义函数
double sqrt(double x);
函数说明
sqrt()用来计算参数x的平方根，然后将结果返回。参数x必须为正数。
返回值
返回参数x的平方根值。
错误代码
EDOM 参数x为负数。
附加说明
使用GCC编译时请加入-lm。
范例
/* 计算200的平方根值*/
#include<math.h>
main()
{
double root;
root = sqrt (200);
printf("answer is %f\n",root);
}
执行
answer is 14.142136
　



tan（取正切函数值）
相关函数
atan，atan2，cos，sin
表头文件
#include <math.h>
定义函数
double tan(double x);
函数说明
tan()用来计算参数x的正切值，然后将结果返回。
返回值
返回参数x的正切值。
附加说明
使用GCC编译时请加入-lm。
范例
#include<math.h>
main()
{
double answer = tan(0.5);
printf("tan (0.5) = %f\n",answer);
}
执行
tan(0.5) = 0.546302
　



tanh（取双曲线正切函数值）
相关函数
cosh，sinh
表头文件
#include<math.h>
定义函数
double tanh(double x);
函数说明
tanh()用来计算参数x的双曲线正切值，然后将结果返回。数学定义式为:sinh(x)/cosh(x)。
返回值
返回参数x的双曲线正切值。
附加说明
使用GCC编译时请加入-lm。
范例
#include<math.h>
main()
{
double answer = tanh(0.5);
printf("tanh(0.5) = %f\n",answer);
}
执行
tanh(0.5) = 0.462117
　


