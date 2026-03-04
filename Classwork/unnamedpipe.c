#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int pipfd[2]={0,0};
    int iRet=0;

    iRet=pipe(pipfd);

    if(iRet==0)
    {
        printf("Unnamed pipe get created\n");
    }

    return 0;
}