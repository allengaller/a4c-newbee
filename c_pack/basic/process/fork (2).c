#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
/*
int main(void)
{
	pid_t pid;
	
	printf("Process Creation Study.\n");
	pid = fork();
	switch(pid)
	{
	case 0:
	printf("Child process is running, CurPid is %d, ParentPid is %d\n", pid, getppid());
	break;

	case -1:
	perror("Process creation failed.\n");
	break;

	default:
	printf("Parent process is running, ChildPid is %d, ParentPid is %d\n", pid, getppid());
	break;
	}
	exit(0);
}
*/

main()
{
	int i = 1;
	if(fork()==0)
	{
	printf("This is the child process.\n");
	printf("pid=%d\n",getpid());
	i = 2;
	printf("i=%d\n",i);
	}else
	{
	printf("This is the parent process.\n");
	printf("pid=%d\n",getpid());
	printf("i=%d\n",i);
	}
}
