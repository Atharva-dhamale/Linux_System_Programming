#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
    void *handle=NULL;
    char *error=NULL;
    int ch,a,b=0;

    int (*Addition)(int,int);
    int (*Subtraction)(int,int);
    

    handle = dlopen("./libServer.so", RTLD_LAZY);

    if(!handle)
    {
        printf("Library load failed: %s\n", dlerror());
        return 1;
    }

    dlerror();

    Addition  = dlsym(handle, "Addition");
    Subtraction  = dlsym(handle, "Subtraction");
    
    if((error = dlerror()) != NULL)
    {
        printf("Symbol error: %s\n", error);
        dlclose(handle);
        return 1;
    }

    

    printf("1.Add\n2.Sub\n");
    printf("Enter choice: ");
    scanf("%d",&ch);

    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);

    switch(ch)
    {
        case 1: printf("Result = %d\n",Addition(a,b));
        {
            break;
        }
        case 2: printf("Result = %d\n",Subtraction(a,b));
        {
            break;
        }
        default:
        {
            printf("Invalid choice\n");
        }
    }

    dlclose(handle);
    return 0;
}
