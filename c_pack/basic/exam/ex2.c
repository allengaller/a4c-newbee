#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

//增值和累加的变量的最大值
#define VAR_MAX 10000

//定义bool值，C语言默认没有
#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

//累加完成信号量
sem_t acc_over_sem;
//增值完成信号量
sem_t add_over_sem;
//程序执行状态
static unsigned char running_status = TRUE;

//要操作进行增值和累加的变量
static unsigned int var = 0;

//累加线程函数
static void acc_thread(void* param)
{
    unsigned int acc_value = 0;

    while(running_status){
        acc_value += var;

        //设置累加完成信号量
        sem_post(&acc_over_sem);
        //等待下一次增值完成信号量
        sem_wait(&add_over_sem);
    }

    printf("acc valud is : %u\n", acc_value);
}

//增值线程函数
static void add_thread(void* param)
{
    while(running_status){
        //等待累加完成信号量
        sem_wait(&acc_over_sem);

        if(var >= VAR_MAX){
            running_status = FALSE;
        }else{
            //使var变量增值
            var++;
        }

        //设置增值完成信号量
        sem_post(&add_over_sem);
    }
}

int main(void)
{
    //线程ID变量
    pthread_t acc_pid, add_pid;

    //初始化信号量
    sem_init(&add_over_sem, 0, 0);
    sem_init(&acc_over_sem, 0, 0);

    //建立线程
    pthread_create(&acc_pid, NULL, (void *)acc_thread, NULL);
    pthread_create(&add_pid, NULL, (void *)add_thread, NULL);

    pthread_join(acc_pid, NULL);
    pthread_join(add_pid, NULL);

    sem_destroy(&acc_over_sem);
    sem_destroy(&add_over_sem);

    return 0;
}


