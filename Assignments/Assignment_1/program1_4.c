#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

int main()
{
    char fileName[50];
    int iRet=0;
    struct stat sobj;
    
    

    printf("Enter the file name:");
    scanf("%s",fileName);

    

    

    iRet=stat(fileName,&sobj);

    printf("Size:%ld\n",sobj.st_size);
    printf("Inode number:%lu\n",sobj.st_ino);
    printf("Permission:%o\n",sobj.st_mode&0777);
    printf("Hard link:%ld\n",sobj.st_nlink);
    printf("User Id:%d\n",sobj.st_uid);
    printf("Group Id:%d\n",sobj.st_gid);
    
    printf("Last Access time:%ld\n",sobj.st_atime);
    printf("Last Modify time:%ld\n",sobj.st_mtime);

    printf("File type:");

    if(S_ISREG(sobj.st_mode))
    {
        printf("Regular file\n");
    }
    else if(S_ISDIR(sobj.st_mode))
    {
        printf("Directory file\n");
    }
    else if(S_ISLNK(sobj.st_mode))
    {
        printf("Symbolic link\n");
    }
    else if(S_ISBLK(sobj.st_mode))
    {
        printf("Block device\n");
    }
    else if(S_ISCHR(sobj.st_mode))
    {
        printf("Charcater device\n");
    }
    else if(S_ISFIFO(sobj.st_mode))
    {
        printf("FIFO\n");
    }
    else if(S_ISSOCK(sobj.st_mode))
    {
        printf("Socket\n");
    }

    else
    {
        printf("Other\n");
    }

   


    return 0;
}