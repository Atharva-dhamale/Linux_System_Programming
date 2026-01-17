#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int iRet=0;
    int fd=0;

    fd=open("Demo.txt",O_RDWR);
    iRet=ftruncate(fd,5);

    if(iRet==0)
    {
        printf("Truncate is succesful\n");
    }
    else
    {
        printf("Truncate has isssue \n");
    }

    return 0;
}