#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

int main()
{
    char fileName[50];
    int fd=0;

    printf("Enter the file name:");
    scanf("%s",fileName);

    fd=open(fileName,O_RDONLY|O_CREAT);

    if(fd==-1)
    {
        perror("Error opening file");
    }
    else
    {
        printf("File created succesfully with fd:%d\n",fd);
    }
    close(fd);

    return 0;
}