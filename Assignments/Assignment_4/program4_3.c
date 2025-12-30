#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd1, fd2;
    char buf[1];
    int pos = 0;

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_CREAT | O_WRONLY, 0777);

    while (pread(fd1, buf, 1, pos) > 0)
    {
        pwrite(fd2, buf, 1, pos);
        pos++;
    }

    close(fd1);
    close(fd2);

    return 0;
}
