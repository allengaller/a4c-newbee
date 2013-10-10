#include<signal.h>
#include<stdio.h>
#include<stdlic.h>

int main(int argc, char **argv)
{
	union sigval value;
	int signum = SIGTERM;
	pid_t pid;
	int i;

	//初始化
	value.sival_int = 0;

	//检查参数的个数
	if(argc != 3 && argc != 5 && argc != 7)
	{
	printf("./send_data_signo <-d data> <-s signum> [-p][data]\n");
	exit(1);
	}

	for(i = 1; i< argc; i++)
	{
		if(!strcmp(argv[i],"-d"))
		{
			value.sival_int = atoi(argv[i+1]);//atoi()将字符串转换成整数
			continue;
		}
	}
}
