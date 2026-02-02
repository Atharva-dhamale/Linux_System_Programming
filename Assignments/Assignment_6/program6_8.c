#include <stdio.h>
#include <dlfcn.h>

int main()
{
    char str[100];

    void *handle;
    int (*Lower)(char *);
    int (*Upper)(char *);
    int (*Digits)(char *);

    printf("Enter string: ");
    fgets(str, 100, stdin);

    handle = dlopen("./libServer2.so", RTLD_LAZY);

    Lower  = dlsym(handle, "CountLower");
    Upper  = dlsym(handle, "CountUpper");
    Digits = dlsym(handle, "CountDigits");

    printf("Lowercase: %d\n", Lower(str));
    printf("Uppercase: %d\n", Upper(str));
    printf("Digits   : %d\n", Digits(str));

    dlclose(handle);
    return 0;
}
