#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *out, *in;
    char ch;
    int i;

    out = fopen(argv[1], "w");

    for (i = 2; i < argc; i++)
    {
        in = fopen(argv[i], "r");

        while ((ch = fgetc(in)) != EOF)
        {
            fputc(ch, out);
        }
            

        fclose(in);
    }

    fclose(out);
    return 0;
}
