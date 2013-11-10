#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>     //包含信号量库

void *thread_function(void *arg); //定义线程函数原型

sem_t bin_sem;     //定义信号量
#define WORK_SIZE 1024  
char work_area[WORK_SIZE];  //定义公用的内存空间

int main()
{
	int res;
	pthread_t a_thread;  //用于保存创建线程的返回值
	void *thread_result; //用于接受线程结束时的返回值
	res = sem_init(&bin_sem, 0,0); //创建并初始化信号量
	if(res!=0)//判断创建线程是否有错误
	{
	perror("初始化信号量失败");	
	exit(EXIT_FAILURE);
	}
	res = pthread_create(&a_thread, NULL, thread_function,NULL);//创建线程
	if(res!=0) //判断创建线程是否有错误
	{
	perror("线程创建失败");
	exit(EXIT_FAILURE);
	}
	printf("请输入要传送的信息，输入‘end’退出\n");
	while(strncmp("end",work_area, 3)!=0)//判断输入的是否是end
	{
	fgets(work_area,WORK_SIZE,stdin);//接收输入信号
	sem_post(&bin_sem);//信号量加1
	}
	printf("\n等待线程结束...\n");
	res = pthread_join(a_thread, &thread_result);//等待线程结束
	if(res != 0)  //判断结束线程是否有错误
	{
		perror("线程结束失败");	
		exit(EXIT_FAILURE);
	}
	printf("线程结束\n");
	sem_destroy(&bin_sem); // 消除信号量
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)//定义线程函数细节
{
	sem_wait(&bin_sem); //等待信号量变化，将信号量减1
	while(strncmp("end",work_area, 3)!=0){    //判断收到的信息是否是end
	printf("收到%d个字符\n",strlen(work_area) - 1); //输出接受到信息的字符数量
	sem_wait(&bin_sem);	//等待信号量变化，将信号量减1
	}
	pthread_exit(NULL); //结束线程
}

