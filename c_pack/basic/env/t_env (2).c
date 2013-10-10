
getenv（取得环境变量内容）
相关函数
putenv，setenv，unsetenv
表头文件
#include<stdlib.h>
定义函数
char * getenv(const char *name);
函数说明
getenv()用来取得参数name环境变量的内容。参数name为环境变量的名称，如果该变量存在则会返回指向该
内容的指针。环境变量的格式为name＝value。
返回值
执行成功则返回指向该内容的指针，找不到符合的环境变量名称则返回NULL。

范例

#include<stdlib.h>
main()
{
    char *p;
    if((p = getenv(“USER”)))
        printf(“USER=%s\n”,p);
}

执行

USER = root
　
================================================================================

putenv（改变或增加环境变量）
相关函数
getenv，setenv，unsetenv
表头文件
#include4<stdlib.h>
定义函数
int putenv(const char * string);
函数说明
putenv()用来改变或增加环境变量的内容。参数string的格式为name＝value，如果该环境变量原先存在，
则变量内容会依参数string改变，否则此参数内容会成为新的环境变量。
返回值
执行成功则返回0，有错误发生则返回-1。
错误代码
ENOMEM 内存不足，无法配置新的环境变量空间。

范例

#include<stdlib.h>
main()
{
    char *p;
    if((p = getenv(“USER”)))
        printf("USER =%s\n",p);
        putenv("USER=test");
        printf("getenv= %s\n",getenv("USER"));
}

执行

USER=root
USER=root
　
================================================================================

setenv（改变或增加环境变量）
相关函数
getenv，putenv，unsetenv
表头文件
#include<stdlib.h>
定义函数
int setenv(const char *name,const char * value,int overwrite);
函数说明
setenv()用来改变或增加环境变量的内容。参数name为环境变量名称字符串。
参数
value则为变量内容，参数overwrite用来决定是否要改变已存在的环境变量。如果overwrite不为0，而该
环境变量原已有内容，则原内容会被改为参数value所指的变量内容。如果overwrite为0，且该环境变量已有
内容，则参数value会被忽略。
返回值
执行成功则返回0，有错误发生时返回-1。
错误代码
ENOMEM 内存不足，无法配置新的环境变量空间

范例

#include<stdlib.h>
main()
{
    char * p;
    if((p=getenv(“USER”)))
        printf("USER =%s\n",p);
        setenv(“USER” , ”test” , 1);
        printf(“USER=%s\n” , getenv(“USEr”));
        unsetenv(“USER”);
        printf(“USER=%s\n” , getenv(“USER”));
}

执行

USER = root
USER = test
USER = (null)
　
================================================================================

