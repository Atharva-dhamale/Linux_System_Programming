#include <stdio.h>

void Display(char *);

int main()
{
    char str[100];

    printf("Enter string: ");
    fgets(str, 100, stdin);

    Display(str);

    return 0;
}
