#include<stdio.h>
#include<pthread.h>

void * Demo(void *p)
{
    printf("Inside thread\n");
    return NULL;
}

int main()
{
    pthread_t TID;
    int iRet=0;

    printf("Main Thread started\n");
    

    iRet=pthread_create(&TID,       //Thread ID
                        NULL,       //Thread attributes
                        Demo,       //Thread callback function
                        NULL        //Parameter for callback function
                    );

    if(iRet==0)
    {
        printf("Thread gets created succesfully\n");
    }

    printf("End of main Thread\n");

    return 0;
}