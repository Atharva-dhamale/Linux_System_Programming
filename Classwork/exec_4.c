#include<stdio.h>
#include<unistd.h>

int main()
{
    pid_t pid=0;

    pid=fork();

    if(pid==0)
    {
        printf("CHILD SAYS : PID of current proccess: %d, PID of parrent :%d, Return value of fork :%d\n",getpid(),getppid(),pid);
        execl("./commandexe","First","Demo","Pune","121",NULL);
    }
    else
    {
        printf("PARENT SAYS : PID of current proccess: %d, PID of parrent :%d, Return value of fork :%d\n",getpid(),getppid(),pid);
    }

    

    return 0;
}