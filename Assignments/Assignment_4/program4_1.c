#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *src, *dest;
    char ch;

    if (argc != 3)
    {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    src = fopen(argv[1], "r");
    if (src == NULL)
    {
        printf("Error: Source file not found or permission denied\n");
        return 1;
    }

    dest = fopen(argv[2], "w");
    if (dest == NULL)
    {
        printf("Error: Cannot create destination file\n");
        fclose(src);
        return 1;
    }

    while ((ch = fgetc(src)) != EOF)
    {
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);

    printf("File copied successfully.\n");
    return 0;
}
