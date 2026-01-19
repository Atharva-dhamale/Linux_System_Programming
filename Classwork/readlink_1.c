#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>


int main()
{
    int fd=0;

    fd=open("./Test.LSPl.txt",O_RDONLY);                        //Isuue

    if(fd==-1)
    {
        printf("Unable to open file: %s\n",strerror(errno));
        return -1;
    }

    printf("file open with :%d\n",fd);

    close(fd);

    return 0;
}