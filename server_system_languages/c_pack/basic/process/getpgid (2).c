/*取得init 进程（pid＝1）的组识别码*/
#include<unistd.h>
#include<stdio.h>

main()
{
    printf( "init gid = %d\n ",getpgid(1));
}
