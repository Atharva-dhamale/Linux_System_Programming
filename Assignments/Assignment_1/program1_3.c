#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>

int main()
{
    char fileName[50];
    char mode[50];
    int fd=0;
    int flags=0;
    int accessMode=0;
    int checkMode=0;

    printf("Enter the file name:");
    scanf("%s",fileName);

    printf("Enter the flag mode (R,W,RW,A): ");
    scanf("%s",mode);

    if(strcmp(mode,"R")==0)
    {
        flags=O_RDONLY|O_CREAT;
        checkMode=R_OK;
    }
    else if(strcmp(mode,"W")==0)
    {
        flags=O_WRONLY|O_CREAT;
        checkMode=W_OK;
    }
    else if(strcmp(mode,"RW")==0)
    {
        flags=O_RDWR|O_CREAT;
        checkMode=R_OK|W_OK;
    }
    else if(strcmp(mode,"A")==0)
    {
        flags=O_RDWR|O_APPEND|O_CREAT;
    }

    fd=open(fileName,flags,0777);

    if(fd==-1)
    {
        perror("Error opening file");
    }
    else
    {
        printf("File created succesfully with fd:%d\n",fd);
    }

    accessMode=access(fileName,checkMode);
    
    if(accessMode==0)
    {
        perror("Accesible");
    }
    else
    {
        perror("Inaccesible");
    }

    close(fd);

    return 0;
}