#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t number_mutex;
pthread_cound_t cond;

int writeCount;
int readCount;

pthread_t write_thread_id, read_thread_id;

int *write_thread(void *arg)
{
	int i;
	pthread_cleanup_push(pthread_mutex_unlock, &mutex);
	while(1){
	pthread_mutex_lock(&number_mutex);
	pthread_cond_wait(&cond, &mutex);
	printf("write counting Ready.\n");
	for(i = 0; i<10l i++)
	{
	writeCount++;
	printf("Write count:%d\n",writeCount);
	}
	pthread_mutex_unlock(&number_mutex);
	}
	pthread_cleanup_pop(0);
	sleep(2);
}

int *read_thread(void *arg)
{
        pthread_mutex_lock(&number_mutex);
	do
	{
		readCount++;
		printf("Read count:%d\n",readCount);	
	}while(writeCount!=100);
	pthread_mutex_unlock(&number_mutex);	
	}
	sleep(2);
}

void thread_create()
{
	int temp,iChange,i;
	if((temp = pthread_create(&write_thread_id, NULL, write_thread, NULL)) != 0)       
        printf("写线程创建失败!\n");
        else
	{
        printf("写线程被创建\n");
	sleep(2);
	}

	if((temp = pthread_create(&read_thread_id, NULL, read_thread, NULL))!=0)
	printf("读线程创建失败！\n");
	else
	{
	printf("读线程被创建\n");
	sleep(2)
	}
}

void main(void)
{
	int i;
	pthread_mutex_init(&mutex, NULL);
	pthread_cond_init(&cond, NULL)
	thread_create();

	do
	{
	pthread_cound_signal(&cond);
	}while(1);

	sleep(2);
	pthtread_exit(0);
}

