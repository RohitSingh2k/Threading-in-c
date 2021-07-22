/*
 * Date : 19 July 2021
 * Author : Rohit Singh
 * Purpose : To show implementation of thread and how to pass arguments in thread functions.
 *
 */

#include<stdio.h>
#include<math.h>
#include<pthread.h>

// Creating a structure that contains arr data.
struct arr_val{
    int *arr;
    int n;
};

// This function simply calculates sum of all the elements present in the arr.
int calculate_sum(int *arr,int n)
{
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum += arr[i];
    }
    printf("\nSum = %d",sum);
}

// Thread function which calls calculate_sum function.
void *sum(void *args)
{
    // Declaring a pointer to structure which holds arguments. 
    struct arr_val *var;
    var = (struct arr_val *)args;
    
    // Calling calculate_sum function with required arguments.
    calculate_sum(var->arr,var->n);
    
    // exiting thread.
    pthread_exit(NULL);
}

// Thead function for calculating power of a.
void *power(void *args)
{
    // Taking arguments.
    int a = *(int *) args;

    // Calculating square of a.
    printf("\nSquare of %d = %d",a,(int)pow(a,2));

    // exiting pointer.
    pthread_exit(NULL);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,9,8};
    // Creating thread id variable.
    pthread_t id[2];
    
    // Declaring structure variable and assigning it.
    struct arr_val my_arr;
    my_arr.arr = arr;
    my_arr.n = sizeof(arr)/sizeof(arr[0]);

    // Creating threads for sum and power calculation.
    pthread_create(&id[0],NULL,sum,(void *) &my_arr);
    pthread_create(&id[1],NULL,power,(void *) &my_arr.n);
    // Code of this area is not wait for the threads to be executed and run parallel with threads. 
    
    printf("\nIn main function");

    pthread_join(id[0],NULL);
    pthread_join(id[1],NULL);
    // Code of this area is executed after all the thread is being executed.
    
    printf("\nAt the end\n");
    return 0;
}

