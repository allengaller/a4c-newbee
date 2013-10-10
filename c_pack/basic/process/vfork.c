#include<unistd.h>
#include<stdio.h>

main()
{
    if(vfork() == 0)
    {
        printf("This is the child process\n");
    } else {
        printf("This is the parent process\n");
    }
}
