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
    char fileName[50];
    DIR *dp=NULL;
    struct dirent *ptr=NULL;
    char path[1024];
    
    

    printf("Enter the Directory name:");
    scanf("%s",DirName);

    dp=opendir(DirName);

    if(dp==NULL)
    {
        printf("Directory not found\n");
        return 1;
    }
    

    printf("Enter the File name:");
    scanf("%s",fileName);
   

    
    

    while((ptr=readdir(dp))!=NULL)
    {
        if(strcmp(ptr->d_name,fileName)==0)
        {
            realpath(DirName,path);
            printf("File found at: %s/%s\n",path,fileName);
            closedir(dp);
            return 0;
        }
    }

    printf("File not found\n");
    closedir(dp);

    return 0;
}


