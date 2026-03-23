#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>

int main()
{
    int id=0;
    id=shmget(11,1024,0666|IPC_CREAT);

    if(id!=-1)
    {
        printf("Shared memory gets allocted by server\n");
    }
    

    return 0;
}