#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

int main()
{
    printf("Current directory name :%s\n",getcwd());        //error

    return 0;
}