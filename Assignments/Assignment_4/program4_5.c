#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    long size;
    char ch;

    fp = fopen(argv[1], "r");

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);      

    while (size--)
    {
        fseek(fp, size, SEEK_SET);
        ch = fgetc(fp);
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}
