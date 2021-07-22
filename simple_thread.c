/*
 * Date : 19 July 2021
 * Author : Rohit Singh
 * Purpose : To show implementing simple threading.
 *
 */


#include<stdio.h>
#include<pthread.h>

// This is a thread function.
void *thread_func(void *args)
{
    // pthread_self() -> returns id of the current thread.
    for(int i = 1; i <= 10;i++) printf("thread id = %ld printing the value : %d\n",pthread_self(),i);
    pthread_exit(NULL);
}

// This is another thread function.
void *thread_func2(void *args)
{
    for(int i = 1; i <= 10;i++) printf("thread id = %ld printing the value : %d\n",pthread_self(),i);
    pthread_exit(NULL);
}

int main()
{
    // Declaring thread id for each thread function.
    pthread_t id[2];
    
    printf("Creating threads ...\n\n");

    // Creating threads.
    pthread_create(&id[0],NULL,thread_func,NULL);
    pthread_create(&id[1],NULL,thread_func2,NULL);
    
    // Waiting for the thread being executed.
    pthread_join(id[0],NULL);
    pthread_join(id[1],NULL);

    printf("\nAll threads are executed properly\n");
    return 0;
}

