#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd1, fd2, off;
    char ch;

    off = atoi(argv[3]);

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_CREAT | O_WRONLY, 0777);

    lseek(fd1, off, SEEK_SET);

    while (read(fd1, &ch, 1) > 0)
    {
        write(fd2, &ch, 1);
    }
        

    close(fd1);
    close(fd2);

    return 0;
}
