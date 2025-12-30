#include<stdio.h>
#include<errno.h>               //library for error
#include<fcntl.h>               //library for file control
#include<string.h>

int main()
{
    int fd=0;
    fd=open("Demo.txt",O_RDONLY);
    printf("Value of fd is %d\n",fd);

    if(errno!=0)
    {
        printf("Value of errno is %d\n",errno);
        printf("Error statement:%s\n",strerror(errno));
    }
    
    
    return 0;
}