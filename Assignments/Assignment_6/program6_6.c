#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    int (*Addition)(int,int);
    char *error;

    handle = dlopen("libServer.so", RTLD_LAZY);

    if(!handle)
    {
        printf("Load failed: %s\n", dlerror());
        return 1;
    }

    Addition = dlsym(handle,"Addition");

    if((error = dlerror()) != NULL)
    {
        printf("Symbol error: %s\n", error);
        return 1;
    }

    printf("Result = %d\n", Addition(5,3));

    dlclose(handle);
    return 0;
}
