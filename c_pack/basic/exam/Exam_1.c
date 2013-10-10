/* example.c*/
#include <stdio.h>
#include <pthread.h>
#include<semaphore.h>     //包含信号量库

int number;
pthread_mutex_t mut;
pthread_t thread[10];
sem_t bin_sem;     //定义信号量

void *thread1(void *arg)
{	
	while(1){
	sem_wait(&bin_sem);
	printf("I am thread1.\n");
	}
}

void *thread2(void)
{
	
}

void *thread3(void)
{
	printf("I am thread3.\n");
	sleep(2);
}

void *thread4(void)
{
	printf("I am thread4.\n");
	sleep(2);
}

void *thread5(void)
{
	printf("I am thread5.\n");
	sleep(2);
}

void *thread6(void)
{
	printf("I am thread6.\n");
	sleep(2);
}

void *thread7(void)
{
	printf("I am thread7.\n");
	sleep(2);
}

void *thread8(void)
{
	printf("I am thread8.\n");
	sleep(2);
}

void *thread9(void)
{
	printf("I am thread9.\n");
	sleep(2);
}

void *thread10(void)
{
	printf("I am thread10.\n");
	sleep(2);
	//pthread_exit(0);
}      

void thread_create(void)
{
	int ret;
		
	ret=pthread_create(&thread[1],NULL,(void *) thread1,NULL);
	ret=pthread_create(&thread[2],NULL,(void *) thread2,NULL);
	ret=pthread_create(&thread[3],NULL,(void *) thread3,NULL);
	ret=pthread_create(&thread[4],NULL,(void *) thread4,NULL);
	ret=pthread_create(&thread[5],NULL,(void *) thread5,NULL);
	ret=pthread_create(&thread[6],NULL,(void *) thread6,NULL);
	ret=pthread_create(&thread[7],NULL,(void *) thread7,NULL);
	ret=pthread_create(&thread[8],NULL,(void *) thread8,NULL);
	ret=pthread_create(&thread[9],NULL,(void *) thread9,NULL);
	ret=pthread_create(&thread[10],NULL,(void *) thread10,NULL);

	if(ret!=0)//pthread_create()返回值要等于0就成功
	{
	printf ("Create pthread error!\n");
	exit (1);
	}
}


int main(void)
{
	sem_init(&bin_sem, 0,0); //创建并初始化信号量
	printf("main process created.\n");
	thread_create();
	int number;
	printf("Input pthread ID:");
	scanf("%d", &number);
	printf("You choosed:%d\n",number);
	switch(number)
	{
	case 1:	
		sem_post(&bin_sem);//信号量加1
		//printf("I am thread1.\n");
                pthread_join(thread[1],NULL);  
		break;  
	case 2:    
		printf("I am thread2.\n");    
                pthread_join(thread[2],NULL);    
		break;
	case 3:         
		printf("I am thread3.\n");
                pthread_join(thread[3],NULL);  
		break;
	case 4:           
		printf("I am thread4.\n");
                pthread_join(thread[4],NULL);    
		break;
	case 5:          
		printf("I am thread5.\n");
                pthread_join(thread[5],NULL); 
		break;
	case 6:         
		printf("I am thread6.\n");  
                pthread_join(thread[6],NULL);  
		break; 
	case 7:        
		printf("I am thread7.\n"); 
                pthread_join(thread[7],NULL);  
		break;  
	case 8:        
		printf("I am thread8.\n"); 
                pthread_join(thread[8],NULL);  
		break;
	case 9:      
		printf("I am thread9.\n");     
                pthread_join(thread[9],NULL);  
		break;
	case 10:      
		printf("I am thread10.\n");   
                pthread_join(thread[10],NULL);
		break;
	}
	return (0);
}

