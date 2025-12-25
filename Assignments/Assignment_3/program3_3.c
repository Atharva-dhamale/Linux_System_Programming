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
    char SrcDir[50];
    char DestDir[50];
    char SrcPath[200];
    char DestPath[200];
    DIR *dp=NULL;
    struct dirent *ptr=NULL;
    char path[1024];
    int iCnt=0;
    struct stat sobj;
    
    

    printf("Enter the Source Directory name:");
    scanf("%s",SrcDir);

    dp=opendir(SrcDir);

    if(dp==NULL)
    {
        printf("Source Directory not found\n");
        return 1;
    }

    printf("Enter the Destination Directory name:");
    scanf("%s",DestDir);

    while ((ptr = readdir(dp)) != NULL)
    {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
        {
            continue;
        }

        sprintf(SrcPath, "%s/%s", SrcDir, ptr->d_name);
        sprintf(DestPath, "%s/%s", DestDir, ptr->d_name);

        stat(SrcPath, &sobj);

        
        if (S_ISREG(sobj.st_mode))
        {
            rename(SrcPath, DestPath);
            iCnt++;
        }
    }

    closedir(dp);

    printf("Total files moved: %d\n", iCnt);

    return 0;
}
