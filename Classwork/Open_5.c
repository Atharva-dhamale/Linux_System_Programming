#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>          //library for close();

int main()
{
    int fd=0;

    fd=open("Second.c",O_CREAT|O_TRUNC,0777);

    if(fd==-1)
    {
        printf("Unable to create file\n");
    }
    else
    {
        printf("File gets succesfully created with fd : %d\n",fd);
    }

    close(fd);
    return 0;
}