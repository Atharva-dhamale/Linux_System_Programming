#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *entry;
    struct stat st;
    char path[512];

    dp = opendir(argv[1]);

    while ((entry = readdir(dp)) != NULL)
    {
        
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }
            

        
        snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);

        stat(path, &st);

        
        printf("Name: %s\n", entry->d_name);

        
        if (S_ISREG(st.st_mode))
        {
            printf("Type: File\n");
        }
        else if (S_ISDIR(st.st_mode))
        {
            printf("Type: Directory\n");
        }
        else if (S_ISLNK(st.st_mode))
        {
            printf("Type: Link\n");
        }
        else
        {
            printf("Type: Other\n");
        }

        
        printf("Size: %ld bytes\n", st.st_size);

        
        printf("Permissions: ");
        printf( (st.st_mode & S_IRUSR) ? "r" : "-");
        printf( (st.st_mode & S_IWUSR) ? "w" : "-");
        printf( (st.st_mode & S_IXUSR) ? "x" : "-");
        printf( (st.st_mode & S_IRGRP) ? "r" : "-");
        printf( (st.st_mode & S_IWGRP) ? "w" : "-");
        printf( (st.st_mode & S_IXGRP) ? "x" : "-");
        printf( (st.st_mode & S_IROTH) ? "r" : "-");
        printf( (st.st_mode & S_IWOTH) ? "w" : "-");
        printf( (st.st_mode & S_IXOTH) ? "x\n" : "-\n");

        
        printf("Modified: %s\n", ctime(&st.st_mtime));

        printf("-----------------------------\n");
    }

    closedir(dp);
    return 0;
}
