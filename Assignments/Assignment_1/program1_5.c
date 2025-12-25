#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>


int main()
{
    char fileName[50];
    char buff[1024];
    int fd=0;
    int n=0;
    

    printf("Enter the file name:");
    scanf("%s",fileName);

    printf("Enter the bytes to read:");
    scanf("%d",&n);

    fd=open(fileName,O_RDONLY);

    read(fd,buff,n);

    printf("Read bytes are :%s\n",buff);

    return 0;
}