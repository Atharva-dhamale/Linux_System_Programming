#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

int main()
{
    char Arr[50];

    memset(Arr,'\0',sizeof(Arr));

    getcwd(Arr,sizeof(Arr));

    printf("Current directory name :%s\n",Arr);

    return 0;
}