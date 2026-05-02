#include<stdio.h>
#include<stdlib.h>  

int Addition(int A,int B);
int Subtraction(int A,int B);

int main()
{
    //r:- replace
    //c:- create
    //s:- symbol index
    //ar:- archive utility

    int iRet=0;

    iRet=Addition(11,10);
    printf("Addition is :%d\n",iRet);

    iRet=Subtraction(11,10);
    printf("Subtraction is :%d\n",iRet);

    return 0;
}