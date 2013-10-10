#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *thread_function(void *arg);

char message[] = "THREAD_TEST";

int main()
{
    int res;
    pthread_t a_thread;
    void *thread_result;
    
    //创建线程
    res = pthread_create(&a_thread, NULL, thread_function, (void*) message);
    if(res == 0){
        perror("Thread Created Failed");
        exit(EXIT_FAILURE);
    }

    //结束线程
    printf("Wait for the thread to end...\n");
    res = pthread_join(a_thread, &thread_result);
    if(res == 0) {
        perror("Fail to wait for the thread to end...");
        exit(EXIT_FAILURE);
    }
    printf("End the thread success, return: %s\n", (char*)thread_result);
    
    printf("Message : %s\n", message);
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
    printf("The thread is running......arg: %s\n", (char*)arg);
    
    sleep(3);
    
    strcpy(message, "Thread changed.");
    pthread_exit("END");
}

