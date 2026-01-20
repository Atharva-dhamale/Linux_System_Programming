#include<stdio.h>
#include<unistd.h>              //library for read and write
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main()
{
    int fd=0;

    char Buffer[]="indiaismycountry";
    int iRet=0;

    fd=open("Demo.txt",O_CREAT|O_WRONLY|O_APPEND,0777);             //Imp

    if(fd<0)
    {
        printf("Unable to open the file\n");
        printf("Reason : %s\n",strerror(errno));
        return -1;
    }

    printf("File succesfully opened with fd:%d\n",fd);

    iRet=write(fd,Buffer,16);

    printf("%d bytes gets succesfully written\n",iRet);
    close(fd);

    return 0;
}