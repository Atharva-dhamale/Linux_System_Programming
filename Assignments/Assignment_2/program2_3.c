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
    
    

    printf("Enter the Directory name:");
    scanf("%s",DirName);

    
    dp=opendir(DirName);

    if(dp==NULL)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }
    

    while((ptr=readdir(dp))!=NULL)
    {
        if((strcmp(ptr->d_name, ".")==0)||(strcmp(ptr->d_name, "..")==0))
        {
            continue;
        }
        fd=open(ptr->d_name,O_RDONLY);
        iRet=read(fd,buff,(sizeof(buff)-1)>0);
        printf("Files in Directory are:%s\n",ptr->d_name);
    }

   

    

    closedir(dp);
    
    return 0;
}


