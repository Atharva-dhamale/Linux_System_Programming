#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
    int pipefd[2]={0,0};
    int iRet=0;
    char Arr[100]={'\0'};

    pipe(pipefd);

    iRet=fork();

    if(iRet==0)                             //Child
    {
        close(pipefd[0]);
        write(pipefd[1],"Jay Ganesh",10);
        exit(0);
    }
    else                                    //Parent
    {
       close(pipefd[1]);
       read(pipefd[0],Arr,10);
       printf("Data from pipe is :%s\n",Arr); 
    }

    write(pipefd[1],"Jay Ganesh",10);

    read(pipefd[0],Arr,10);

    printf("Data from pipe is :%s\n",Arr);

    return 0;
}