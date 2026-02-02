#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle=NULL;
    int (*Addition)(int,int);
    int (*Subtraction)(int,int);
    char *error=NULL;

    handle = dlopen("./libServer.so", RTLD_LAZY);

    if(!handle)
    {
        printf("Library load error: %s\n", dlerror());
        return 1;
    }

    dlerror();

    Addition = dlsym(handle, "Addition");
    Subtraction = dlsym(handle, "Subtraction");

    if((error = dlerror()) != NULL)
    {
        printf("Symbol error: %s\n", error);
        return 1;
    }

    int a = 20, b = 10;

    printf("Addition = %d\n", Addition(a,b));
    printf("Subtraction = %d\n", Subtraction(a,b));

    dlclose(handle);
    return 0;
}
