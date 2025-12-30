#include<stdio.h>
#include<errno.h>               //library for error

int main()
{
    printf("Demonstration of errno\n");
    printf("%d\n",errno);
    return 0;
}