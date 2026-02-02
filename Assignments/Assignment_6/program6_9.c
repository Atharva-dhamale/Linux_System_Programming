#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    int (*fp[3])(int,int);

    handle = dlopen("./libServer3.so", RTLD_LAZY);

    fp[0] = dlsym(handle, "Add");
    fp[1] = dlsym(handle, "Sub");
    fp[2] = dlsym(handle, "Mul");

    int a = 10, b = 5;

    for(int i=0;i<3;i++)
    {
        printf("Function address: %p  Result: %d\n", fp[i], fp[i](a,b));
    }

    dlclose(handle);
    return 0;
}
