
getopt（分析命令行参数）
相关函数

表头文件
#include<unistd.h>
定义函数
int getopt(int argc,char * const argv[ ],const char * optstring);
函数说明
getopt()用来分析命令行参数。参数argc和argv是由main()传递的参数个数和内容。参数optstring 则
代表欲处理的选项字符串。此函数会返回在argv 中下一个的选项字母，此字母会对应参数optstring 中的字
母。如果选项字符串里的字母后接着冒号“:”，则表示还有相关的参数，全域变量optarg 即会指向此额外参
数。如果getopt()找不到符合的参数则会印出错信息，并将全域变量optopt设为“?”字符，如果不希望geto
pt()印出错信息，则只要将全域变量opterr设为0即可。
返回值
如果找到符合的参数则返回此参数字母，如果参数不包含在参数optstring 的选项字母则返回“?”字符，分析
结束则返回-1。

范例

#include<stdio.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc,char **argv)
{
    int ch;
    opterr = 0;
    while((ch = getopt(argc,argv,"a:bcde"))!= -1)
    switch(ch)
    {
        case ‘a’:
            printf("option a:’%s’\n",optarg);
            break;
        case ‘b’:
            printf("option b :b\n");
            break;
        default:
            printf("other option :%c\n",ch);
    }
    printf("optopt +%c\n",optopt);
}

执行

$./getopt –b
option b:b
$./getopt –c
other option:c
$./getopt –a
other option :?
$./getopt –a12345
option a:’12345’
　
================================================================================

isatty（判断文件描述词是否是为终端机）
相关函数
ttyname
表头文件
#include<unistd.h>
定义函数
int isatty(int desc);
函数说明
如果参数desc所代表的文件描述词为一终端机则返回1，否则返回0。
返回值
如果文件为终端机则返回1，否则返回0。
范例
参考ttyname()。
　
================================================================================

select（I/O多工机制）
表头文件
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
定义函数
int select(int n,fd_set * readfds,fd_set * writefds,fd_set * exceptfds,struct ti
meval * timeout);
函数说明
select()用来等待文件描述词状态的改变。参数n代表最大的文件描述词加1，参数readfds、writefds 和
exceptfds 称为描述词组，是用来回传该描述词的读，写或例外的状况。底下的宏提供了处理这三种描述词组
的方式:
FD_CLR(inr fd,fd_set* set)；用来清除描述词组set中相关fd 的位
FD_ISSET(int fd,fd_set *set)；用来测试描述词组set中相关fd 的位是否为真
FD_SET（int fd,fd_set*set）；用来设置描述词组set中相关fd的位
FD_ZERO（fd_set *set）； 用来清除描述词组set的全部位

参数
timeout为结构timeval，用来设置select()的等待时间，其结构定义如下

struct timeval
{
    time_t tv_sec;
    time_t tv_usec;
};

返回值

如果参数timeout设为NULL则表示select（）没有timeout。
错误代码
执行成功则返回文件描述词状态已改变的个数，如果返回0代表在描述词状态改变前已超过timeout时间，当有
错误发生时则返回-1，错误原因存于errno，此时参数readfds，writefds，exceptfds和timeout的值变
成不可预测。
EBADF 文件描述词为无效的或该文件已关闭
EINTR 此调用被信号所中断
EINVAL 参数n 为负值。
ENOMEM 核心内存不足

范例

常见的程序片段:fs_set readset；
FD_ZERO(&readset);
FD_SET(fd,&readset);
select(fd+1,&readset,NULL,NULL,NULL);
if(FD_ISSET(fd,readset){……}
　
================================================================================

ttyname（返回一终端机名称）
相关函数
Isatty
表头文件
#include<unistd.h>
定义函数
char * ttyname(int desc);
函数说明
如果参数desc所代表的文件描述词为一终端机，则会将此终端机名称由一字符串指针返回，否则返回NULL。
返回值
如果成功则返回指向终端机名称的字符串指针，有错误情况发生时则返回NULL。

范例

#include<unistd.h>
#include<sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>
main()
{
    int fd;
    char * file = "/dev/tty";
    fd = open (fiel,O_RDONLY);
    printf("%s",file);
    if(isatty(fd)) {
        printf("is a tty.\n”);
        printf("ttyname = %s \n",ttyname(fd));
    } else printf(" is not a tty\n");
    close(fd);
}

执行

/dev/tty is a tty
ttyname = /dev/tty
　
================================================================================

