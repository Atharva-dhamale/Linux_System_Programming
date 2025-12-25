#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char DirName[100];
    char path[200];
    DIR *dp;
    struct dirent *ptr;
    struct stat sobj;
    int iCnt = 0;

    printf("Enter directory name: ");
    scanf("%s", DirName);

    dp = opendir(DirName);
    if (dp == NULL)
    {
        printf("Directory not found\n");
        return 1;
    }

    while ((ptr = readdir(dp)) != NULL)
    {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
        {
            continue;
        }
        
        sprintf(path, "%s/%s", DirName, ptr->d_name);
        stat(path, &sobj);

        if (S_ISREG(sobj.st_mode) && sobj.st_size == 0)
        {
            unlink(path);
            printf("Deleted: %s\n", ptr->d_name);
            iCnt++;
        }
    }

    closedir(dp);

    printf("Total deleted files: %d\n", iCnt);

    return 0;
}
