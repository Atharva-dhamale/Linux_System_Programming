#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>


int main(int argc,char *argv[])
{
    int src=0;
    int dest=0;
    char buff[1024];
    int bytes=0;


    src = open(argv[1], O_RDONLY);
    dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0777);

    while ((bytes = read(src, buff, sizeof(buff))) > 0)
    {
        write(dest, buff, bytes);
    }

    close(src);
    close(dest);

    printf("File copied successfully\n");

    
    return 0;
}


