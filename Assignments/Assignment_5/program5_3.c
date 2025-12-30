#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int file_count = 0;
int dir_count = 0;
long total_size = 0;
long max_size = 0;
char max_file[256];

void report(char *path)
{
    DIR *dp;
    struct dirent *entry;
    struct stat st;
    char full[512];

    dp = opendir(path);
    if (dp == NULL)
    {
        return;
    }
    
    dir_count++;

    while ((entry = readdir(dp)) != NULL)
    {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
        {
            continue;
        }

        snprintf(full, sizeof(full), "%s/%s", path, entry->d_name);
        lstat(full, &st);

        if (S_ISREG(st.st_mode))
        {
            file_count++;
            total_size += st.st_size;

            if (st.st_size > max_size)
            {
                max_size = st.st_size;
                strcpy(max_file, entry->d_name);
            }
        }
        else if (S_ISDIR(st.st_mode))
        {
            report(full);
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[])
{
    report(argv[1]);

    printf("Total Files      : %d\n", file_count);
    printf("Total Directories: %d\n", dir_count);
    printf("Total Size       : %ld bytes\n", total_size);
    printf("Largest File     : %s (%ld bytes)\n", max_file, max_size);

    return 0;
}
