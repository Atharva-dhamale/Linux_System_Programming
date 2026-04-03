

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Header file inclusion for Project
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define _GNU_SOURCE

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<signal.h>
#include<fcntl.h>
#include<time.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/statvfs.h>



/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Global variable declaration
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////



static volatile sig_atomic_t stop_flag=0;

//ctrl+c handler
static  void sigint_handler(int sig)
{
    (void)sig;

    printf("Marvellous System Logger is terminating...\n");

    //Tells the thread to stop the execution
    stop_flag=1;
}

//Structure which holds all system information
typedef struct 
{
    double cpu;         //CPU usage percentage
    double mem;         //RAM usage percentage
    double disk;        //Harddisk usage percentage
}Snapshot;

//Global object which holds information
static Snapshot snap;

//Mutex lock for critical section
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;


//Default path for disk
static char *disk_path="/";

//sleep timer for log
static int interval_sec=2;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Helper functions defination
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Function to collect cpu information
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

static double cpu_percentage()
{
    //Logic to fetch CPU information
    return 0.0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Function to collect memory information
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

static double mem_percentage()
{
    //Logic to fetch memory information
    return 0.0;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Function to collect disk information
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

static double disk_percentage(char *path)
{
    //Logic to fetch disk information
    return 0.0;
}

//Thread proc for thread which collects system information
static void *collector_thread(void *arg)
{
    double c=0.0 , m=0.0 , d=0.0;

    (void)arg;
    printf("Inside collector thread\n");

    
    //Enter if ctrl+c is not arrived
    while(!stop_flag)
    {
        //Calculate the current resource usage;
        c=cpu_percentage();
        m=mem_percentage();
        d=disk_percentage(disk_path);

        //Start the critical section
        pthread_mutex_lock(&mtx);

        snap.cpu=c;
        snap.mem=m;
        snap.disk=d;

        //End of critical section
        pthread_mutex_unlock(&mtx);
    }

    return NULL;
}

//Thread proc for thread which writes system information in log
static void *logger_thread(void *arg)
{
    double c=0.0 , m=0.0 , d=0.0;
    int i=0;

    (void)arg;
    printf("Inside logger thread\n");

    int fd=0;
    fd=open("Marvellous_log.txt",O_CREAT|O_WRONLY|O_APPEND,0666);

    char welcome[]={"Marvellous System Logger"};

    write(fd,welcome,strlen(welcome));

    while(!stop_flag)
    {
        pthread_mutex_lock(&mtx);

        d=snap.disk;
        c=snap.cpu;
        m=snap.mem;

        pthread_mutex_unlock(&mtx);

        for(i=0;i<interval_sec && !stop_flag;i++)
        {
            sleep(1);
        }
    }

    close(fd);

    return NULL;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Entry point Function of Project
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main(int argc,char *argv[])
{
    //.exe /home/demo
    if(argc==2)
    {
        disk_path=argv[1];
    }

    //.exe /home/demo 5
    else if(argc==3)
    {
        disk_path=argv[1];
        interval_sec=atoi(argv[2]);
    }
    printf("Marvellous System Logger\n");

    printf("Path is : %s\n",disk_path);
    printf("Interval is : %d\n",interval_sec);

    //Structure for handling ctrl+c
    struct sigaction sa;
    memset(&sa,0,sizeof(sa));

    sa.sa_handler=sigint_handler;
    sigaction(SIGINT,&sa,NULL);

    //Thread to collect the information
    pthread_t t_collect;

    //Thread to write data into log
    pthread_t t_log;

    //Create thread to collect information
    pthread_create(&t_collect,NULL,collector_thread,NULL);

    //Create thread to write data into log
    pthread_create(&t_log,NULL,logger_thread,NULL);

    //Main thread waiting for child threads to terminate
    pthread_join(t_collect,NULL);
    pthread_join(t_log,NULL);

    printf("Terminating the Marvellous System Logger\n");

    return 0;
}