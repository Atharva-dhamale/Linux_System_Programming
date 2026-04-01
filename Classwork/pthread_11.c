#include<stdio.h>
#include<pthread.h>

void* Demo(void *p)
{
    printf("Inside Demo thread\n");
    return NULL;
}

void* Hello(void *p)
{
    printf("Inside Hello thread\n");
    return NULL;
}

int main()
{
    pthread_t TID1,TID2;
    int iRet=0;

    printf("Main Thread started\n");
    

    iRet=pthread_create(&TID1,       //Thread ID
                        NULL,       //Thread attributes
                        Demo,       //Thread callback function
                        NULL        //Parameter for callback function
                    );

    if(iRet==0)
    {
        printf("Thread gets created succesfully with TID1 :%lu\n",(unsigned long)TID1);
    }

    iRet=pthread_create(&TID2,       //Thread ID
                        NULL,       //Thread attributes
                        Hello,       //Thread callback function
                        NULL        //Parameter for callback function
                    );

    if(iRet==0)
    {
        printf("Thread gets created succesfully with TID2 :%lu\n",(unsigned long)TID2);
    }

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);

    printf("End of main Thread\n");

    return 0;
}