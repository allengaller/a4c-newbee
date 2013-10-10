#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
main()
{
    pid_t pid;
    int status,i;
    if(fork() == 0) {
    printf("This is the child process .pid =%d\n",getpid());
    exit(5);
    } else {
        sleep(1);
    printf("This is the parent process,\nwait for child...\n");
    pid = wait(&status);
    i = WEXITSTATUS(status);
    printf("child’s pid = %d . exit status=%d\n", pid , i);
    }
}
