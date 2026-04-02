#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd=0;
    int iRet=0,iCount=0,i=0;
    char Buff[1024]={'\0'};

    fd=open("LB.txt",O_RDONLY);

    while((iRet=read(fd,Buff,sizeof(Buff)))!=0)
    {
        for(i=0;i<iRet;i++)
        {
            if((Buff[i]>='a')&&(Buff[i]<='z'))
            {
                iCount++;
            }
        }
    }

    close(fd);

    printf("Number of small characters :%d\n",iCount);
    
    return 0;
}