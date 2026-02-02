#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    int (*Add)(int,int);
    int (*Sub)(int,int);

    handle = dlopen("./libServer.so", RTLD_LAZY);

    if (!handle)
    {
        printf("Library not loaded\n");
        return 1;
    }

    Add = dlsym(handle, "Addition");
    Sub = dlsym(handle, "Substraction");

    printf("Addition = %d\n", Add(10,5));
    printf("Substraction = %d\n", Sub(10,5));

    dlclose(handle);

    return 0;
}
