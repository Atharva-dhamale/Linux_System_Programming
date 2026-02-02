#include <stdio.h>
#include <dlfcn.h>

void test(int flag, const char *name)
{
    void *handle=NULL;
    char *error=NULL;

    printf("\nLoading with %s\n", name);

    handle = dlopen("./libServer.so", flag);

    if(!handle)
    {
        printf("dlopen error: %s\n", dlerror());
        return;
    }

    printf("Library loaded successfully\n");

    dlerror();

    dlsym(handle, "Multiply");

    error = dlerror();

    if(error)
    {
        printf("Symbol error caught: %s\n", error);
    }
    else
    {
        printf("No symbol error detected\n");
    }

    dlclose(handle);
}

int main()
{
    test(RTLD_LAZY, "RTLD_LAZY");
    test(RTLD_NOW, "RTLD_NOW");

    return 0;
}
