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

    printf("Enter the string to write in file:");
    scanf("%s",buff);

    

    fd=open(fileName,O_WRONLY|O_APPEND);

    

    iRet=write(fd,buff,strlen(buff));
    

   

    printf("Written String are :%s\n",buff);
    printf("No. of bytes read are:%d\n",iRet);

    return 0;
}