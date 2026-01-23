#include<stdio.h>
#include<unistd.h>              //library for read and write
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>


int main()
{
    char Path[50];

    getcwd(Path,sizeof(Path));

    printf("Current directory name :%s\n",Path);

    chdir("./Data");

    getcwd(Path,sizeof(Path));
    printf("Current directory name :%s\n",Path);

    
    
    return 0;
}