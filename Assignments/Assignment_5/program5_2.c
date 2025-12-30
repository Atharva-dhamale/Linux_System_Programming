#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void tree(char *path, int depth)
{
    DIR *dp;
    struct dirent *entry;
    struct stat st;
    char full[512];
    int i;

    dp = opendir(path);
    if (dp == NULL)
    {
        return;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
        {
            continue;
        }

        snprintf(full, sizeof(full), "%s/%s", path, entry->d_name);
        lstat(full, &st);

        
        for (i = 0; i < depth; i++)
        {

            printf("  ");

        
            if (S_ISDIR(st.st_mode))
            {
                printf("[D] %s\n", entry->d_name);
            }
            else if (S_ISLNK(st.st_mode))
            {
                printf("[L] %s\n", entry->d_name);
            }
            else
            {
                printf("[F] %s\n", entry->d_name);
            }

            
            if (S_ISDIR(st.st_mode))
            {
                tree(full, depth + 1);
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[])
{
    printf("%s\n", argv[1]);
    tree(argv[1], 1);
    return 0;
}
