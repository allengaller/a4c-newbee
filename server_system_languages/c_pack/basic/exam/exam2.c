#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t number_mutex;
int globalnumber;

void write_globalnumber()
{
	pthread_mutex_lock(&number_mutex);
	globalnumber ++;
	pthread_mutex_unlock(&number_mutex);
	printf("write done.\n");
}

int read_globalnumnber()
{
	int temp;
	pthread_mutex_lock(&number_mutex);
	temp = globalnumber;
	pthread_mutex_unlock(&number_mutex);
	return(temp);
	printf("read done.\n");
}

int main(void)
{
	pthread_t tid1, tid2;
	printf("123\n");
	//pthread_mutex_init(&mutex,NULL);
	wirte_globalnumber();
	read_globalnumber();
	return 0;
}

