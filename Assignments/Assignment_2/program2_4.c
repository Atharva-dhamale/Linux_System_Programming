#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>
#include<errno.h>


int main()
{
    char DirName[50];
    int fd=0;
    int iRet=0;
    char buff[1024];
    DIR *dp=NULL;
    struct dirent *ptr=NULL;
    struct stat sobj;
    char path[100];
    
    

    printf("Enter the Directory name:");
    scanf("%s",DirName);
    printf("\n");

    
    dp=opendir(DirName);

    if(dp==NULL)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }
    
    

    while((ptr=readdir(dp))!=NULL)
    {
       

        fd=open(ptr->d_name,O_RDONLY);
        read(fd,buff,sizeof(buff)-1);
        printf("Files in Directory are:%s\n",ptr->d_name);

        snprintf(path, sizeof(path), "%s/%s", DirName, ptr->d_name);
        
        if(lstat(path, &sobj) == -1)
        {
            perror("lstat");
            continue;
        }
        
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
            printf("\n");
            }

   

    

    closedir(dp);
    
    return 0;
}


