#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int pthread_mutex_lock(pthread_mutex_t *mutex);

int pthread_mutex_trylock(pthread_mutex_t *mutex);

int     lock_var;
time_t  end_time;
int     sum;

void pthread1(void *arg);
void pthread2(void *arg);
void pthread3(void *arg);

int main(int argc, char *argv[])
{
    pthread_t id1,id2,id3;
    pthread_t mon_th_id;
    int ret;
    sum=10;

    end_time = time(NULL) + 10;
    pthread_mutex_init(&mutex, NULL);

    ret = pthread_create(&id1,NULL, (void *)pthread1, NULL);

    if(ret!=0)
        perror("pthread cread1");
        ret = pthread_create(&id2,NULL,(void *)pthread2, NULL);
    
        if(ret!=0)
            perror("pthread cread2");
            ret=pthread_create(&id3,NULL,(void *)pthread3, NULL);

            if(ret!=0)
                perror("pthread cread3");

    pthread_join(id1,NULL);
    pthread_join(id2,NULL);
    pthread_join(id3,NULL);
    exit(0);
}

void pthread1(void *arg)
{
    int i;
    while(time(NULL) < end_time)
    {
        if(pthread_mutex_lock(&mutex)!=0) //lock
        {
            perror("pthread_mutex_lock");
        }
        else
            printf("pthread1:pthread1 lock the variable\n");
            for(i=0;i<2;i++)
            {
                sleep(2);
                lock_var++;
            }
        
        if(pthread_mutex_unlock(&mutex)!=0) //unlock
        {
            perror("pthread_mutex_unlock");
        }   
        else    
            printf("pthread1:pthread1 unlock the variable\n");
            sleep(1);
        }
}

void pthread2(void *arg)
{
    int nolock=0;
    int ret;

    while(time(NULL) < end_time)
    {
        ret = pthread_mutex_trylock(&mutex);//try lock
        
        if(ret == EBUSY)
            printf("pthread2:the variable is locked by pthread1\n");
        else{
            if(ret!=0)
            {
            perror("pthread_mutex_trylock");
            exit(1);
            }
        else
            printf("pthread2:pthread2 got lock.The variable is %d\n",lock_var);
        
        if(pthread_mutex_unlock(&mutex)!=0)//unlock
        {
            perror("pthread_mutex_unlock");
        }
        else
            printf("pthread2:pthread2 unlock the variable\n");
        }
        sleep(1);
    }
}



void pthread3(void *arg)
{
    int nolock=0;
    int ret;
    
    while(time(NULL) < end_time)
    {
        ret=pthread_mutex_trylock(&mutex);
        if(ret==EBUSY)
            printf("pthread3:the variable is locked by pthread1 or 2\n");
        else
        {
            if(ret!=0)
            {
                perror("pthread_mutex_trylock");
                exit(1);
            }
            else
                printf("pthread3:pthread3 got lock.The variable is %d\n",lock_var);
            
            if(pthread_mutex_unlock(&mutex)!=0)
            {
                perror("pthread_mutex_unlock");
            }
            else
                printf("pthread3:pthread2 unlock the variable\n");
        }
        sleep(3);
    }
}
