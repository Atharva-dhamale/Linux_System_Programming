#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle=NULL;
    int (*Addition)(int,int);
    int (*InvalidFunc)(int,int);
    char *error=NULL;

    printf("Loading shared library...\n");

    handle = dlopen("./libServer.so", RTLD_LAZY);

    if(!handle)
    {
        printf("dlopen failed: %s\n", dlerror());
        return 1;
    }

    printf("Library loaded successfully \n\n");

    dlerror(); 

   
    Addition = dlsym(handle, "Addition");

    if((error = dlerror()) == NULL)
    {
        printf("Addition loaded successfully \n");
        printf("Addition Result = %d\n\n", Addition(10,5));
    }
    else
    {
        printf("Error loading Addition: %s\n", error);
    }

    
    InvalidFunc = dlsym(handle, "Multiply"); 

    if((error = dlerror()) != NULL)
    {
        printf("Invalid function error handled \n");
        printf("Message: %s\n\n", error);
    }

    dlclose(handle);
    printf("Library closed successfully\n");

    return 0;
}
