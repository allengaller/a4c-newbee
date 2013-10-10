#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

//线程个数
#define THREAD_CNT 3

//定义bool值，C语言默认没有
#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

//各个线程等待的信号量
sem_t choose_sem[THREAD_CNT];
//程序执行状态
unsigned char running_status = TRUE;

//线程函数1，2，3
static void thread1(void* param)
{
    while(running_status){
        //等待自己的信号量
        sem_wait(&choose_sem[0]);
        //输出自己的线程打印语句
        printf("I am thread 1 :)\n");
    }
}

static void thread2(void* param)
{
    while(running_status){
        sem_wait(&choose_sem[1]);
        printf("I am thread 2 :)\n");
    }
}

static void thread3(void* param)
{
    while(running_status){
        sem_wait(&choose_sem[2]);
        printf("I am thread 3 :)\n");
    }
}

int main(void)
{
    //存放输入字符的变量
    char input_num;
    //线程ID变量
    pthread_t pid1, pid2, pid3;

    //初始化信号量
    sem_init(&choose_sem[0], 0, 0);
    sem_init(&choose_sem[1], 0, 0);
    sem_init(&choose_sem[2], 0, 0);

    //建立线程
    pthread_create(&pid1, NULL, (void *)thread1, NULL);
    pthread_create(&pid2, NULL, (void *)thread2, NULL);
    pthread_create(&pid3, NULL, (void *)thread3, NULL);

    while(running_status){
        printf("please input a thread num:");
        //获取输入
        input_num = getchar();

        //判断输入值，根据输入数值作出相应动作
        switch(input_num){
            case '1':
                sem_post(&choose_sem[0]);
                break;

            case '2':
                sem_post(&choose_sem[1]);
                break;

            case '3':
                sem_post(&choose_sem[2]);
                break;

            case 'q':
                running_status = FALSE;
                break;

            default:
                break;
        }
    }

    sem_destroy(&choose_sem[0]);
    sem_destroy(&choose_sem[1]);
    sem_destroy(&choose_sem[2]);

    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);
    pthread_join(pid3, NULL);
    return 0;
}


