#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>


int main()
{
    char fileName[50];
    char buff[1024];
    int fd=0;
    int iRet=0;
    
    

    printf("Enter the file name:");
    scanf("%s",fileName);

    

    fd=open(fileName,O_RDONLY);

    

    iRet=read(fd,buff,sizeof(buff)-1);

   

    printf("Read bytes are :%s\n",buff);
    printf("No. of bytes read are:%d\n",iRet);

    return 0;
}