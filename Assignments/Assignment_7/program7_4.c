#include <stdio.h>

int MyStrlen(const char *);

int main()
{
    char str[100];

    printf("Enter string: ");
    fgets(str, 100, stdin);

    int len = MyStrlen(str);

    printf("Length: %d\n", len);

    return 0;
}
