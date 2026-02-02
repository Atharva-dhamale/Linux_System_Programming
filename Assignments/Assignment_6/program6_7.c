#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;

    void (*Modify)(int);
    void (*Display)();
    void (*Reset)();

    handle = dlopen("./libServer1.so", RTLD_LAZY);

    Modify = dlsym(handle, "Modify");
    Display = dlsym(handle, "Display");
    Reset  = dlsym(handle, "Reset");

    Modify(10);
    Display();

    Modify(5);
    Display();

    Reset();
    Display();

    dlclose(handle);
    return 0;
}
