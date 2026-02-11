#include<stdio.h>

int main(int argc,char *argv[])
{
    int i=0;

    printf("Inside Commandline process\n");
    printf("Command Line arguments are:");
    for(i=0;i<argc;i++)
    {
        printf("%s\n",argv[i]);
    }
    return 0;

}