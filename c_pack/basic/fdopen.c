/*
表头文件  
#include<stdio.h>

定义函数  
FILE * fdopen(int fildes,const char * mode);

函数说明  
fdopen()会将参数 fildes 的文件描述词，转换为对应的文件指针后返回。
参数 mode 字符串则代表着文件指针的流形态，此形态必须和原先文件描述词读写模式相同。
关于 mode 字符串格式请参考 fopen()。
 
返回值
转换成功时返回指向该流的文件指针。失败则返回NULL，并把错误代码存在errno中。 
*/

#include<stdio.h>

main()
{
    FILE * fp = fdopen(0 , "w+");
    fprintf(fp , "%s\n" , "hello!");
    fclose(fp);
}
 

