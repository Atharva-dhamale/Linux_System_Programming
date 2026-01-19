#include<stdio.h>
#include<string.h>
#include<errno.h>

int main()
{
    int iRet=0;

    iRet=rename("DemoX.txt","Demo.txt");

    if(iRet==0)
    {
        printf("Rename succesful");
    }
    else
    {
        printf("%s\n",strerror(errno));
    }

    return 0;
}