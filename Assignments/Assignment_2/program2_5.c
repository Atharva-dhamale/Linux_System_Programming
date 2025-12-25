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
    DIR *dp=NULL;
    struct dirent *ptr=NULL;
    struct stat sobj;
    char path[100];
    long int MaxSize = 0;
    char MaxFile[50] = "";
    
    

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
       if((strcmp(ptr->d_name, ".")==0)||(strcmp(ptr->d_name, "..")==0))
        {
            continue;
        }

        

        snprintf(path, sizeof(path), "%s/%s", DirName, ptr->d_name);
        
        if(lstat(path, &sobj) == -1)
        {
            perror("lstat");
            continue;
        }
        
       

        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size > MaxSize)
            {
                MaxSize = sobj.st_size;
                strcpy(MaxFile, ptr->d_name);
            }
        }
    }

   

    

    closedir(dp);

    if(MaxSize > 0)
    {
        printf("\nLargest File Name: %s", MaxFile);
        printf("\nLargest File Size: %ld bytes\n", MaxSize);
    }
    else
    {
        printf("\nNo regular files found in directory.\n");
    }
    
    return 0;
}


