#include "threading.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Optional: use these functions to add debug or error prints to your application
#define DEBUG_LOG(msg,...)
//#define DEBUG_LOG(msg,...) printf("threading: " msg "\n" , ##__VA_ARGS__)
#define ERROR_LOG(msg,...) printf("threading ERROR: " msg "\n" , ##__VA_ARGS__)

void* threadfunc(void* thread_func_args)
{
    // TODO: wait, obtain mutex, wait, release mutex as described by thread_data structure
    // hint: use a cast like the one below to obtain thread arguments from your parameter
    //struct thread_data* thread_func_args = (struct thread_data *) thread_param;

    struct thread_data *thread_param = (struct thread_data *)thread_func_args;

    thread_param->thread_complete_success = true;

    printf("\nBEFORE LOCK\n");

    usleep(thread_param->wait_time * 1000);

    if(pthread_mutex_lock(thread_param->mutex_t) != 0)
        printf("\nIssue Locking Mutex\n");
        
    printf("\nAFTER LOCK\n");
    
    usleep(thread_param->release_time * 1000);

    if(pthread_mutex_unlock(thread_param->mutex_t) != 0)
        printf("\nIssue Unlocking Mutex\n");
    
    return thread_param;
}


bool start_thread_obtaining_mutex(pthread_t *thread, pthread_mutex_t *mutex,int wait_to_obtain_ms, int wait_to_release_ms)
{
    /**
     * TODO: allocate memory for thread_data, setup mutex and wait arguments, pass thread_data to created thread
     * using threadfunc() as entry point.
     *
     * return true if successful.
     *
     * See implementation details in threading.h file comment block
     */
    
    struct thread_data *thread_func_args;

    thread_func_args = (struct thread_data *)malloc(sizeof(struct thread_data));
    thread_func_args->mutex_t = mutex;
    thread_func_args->wait_time = wait_to_obtain_ms;
    thread_func_args->release_time = wait_to_release_ms;
    thread_func_args->threadId = thread;

    // printf("\n\n\nCreating Thread: %ld\n", thread_func_args->threadId);
    if(pthread_create(thread_func_args->threadId, NULL, threadfunc, (void *)thread_func_args) == 0)
    {
        thread_func_args->thread_complete_success = true;
        return thread_func_args->thread_complete_success;
    }
    else

    pthread_detach(*thread);
    printf("\nThread was not joinable\n");
    return false;
}

