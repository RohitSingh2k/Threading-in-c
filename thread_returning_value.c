/*
 * Date : 19 July 2021
 * Author : Rohit Singh
 * Purpose : To show how to return something from a thread.
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

// Defining structure for arguments.
struct values{
    char *name;
    int value;
};

// This is a thread function which returns sum of all integers in range n.
void *thread_function(void *args)
{
    // declaring structure pointer for arguments.
    struct values *arguments;
    arguments = (struct values *) args;
    
    // printing which thread id being executed.
    printf("%s is executed!\n",arguments->name);

    // creating an integer pointer and allocating memory to it.
    int *sum_ptr = (int *)malloc(sizeof(int)*1);

    // initialize pointer to 0.
    *sum_ptr = 0;

    // calculating sum.
    for(int i = 1; i <= arguments->value; i++)
        *sum_ptr += i;

    // returning sum from thread.
    return (void *)sum_ptr;
}

int main()
{
    // creating thread id for each thread.
    pthread_t id[2];

    // Declaring two structure valiable.
    struct values first,second;
    
    // Assignning values to structure variables.
    first.name = "Thread 1";
    first.value = 15;

    second.name = "Thread 2";
    second.value = 6;

    // creating pointer which stores returned values from threads.
    int *first_return = NULL;
    int *second_return = NULL;

    // creating two threads.
    pthread_create(&id[0],NULL,thread_function,(void *) &first);
    pthread_create(&id[1],NULL,thread_function,(void *) &second);

    // getting returned values from threads.
    pthread_join(id[0],(void **) &first_return);
    pthread_join(id[1],(void **) &second_return);

    // printing threads.
    printf("Thread 1 returns : %d\n",*first_return);
    printf("thread 2 returns : %d\n",*second_return);

    // Exiting threads.
    pthread_exit(NULL);

}
