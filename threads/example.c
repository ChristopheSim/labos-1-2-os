#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/sysinfo.h>

pthread_t tid[2];

void* doSomeThing(void *arg)
{
    unsigned long i = 0;
    pthread_t id = pthread_self();

    /*
    if(pthread_equal(id,tid[0]))
    {
        printf("\n First thread processing\n");
        printf("\n %d \n", getpid());
    }
    else
    {
        printf("\n Second thread processing\n");
        printf("\n %d \n", getpid());
    }
    */
    printf("\n N° process: %d \n",getpid());

    for(i=0; i<(0xFFFFFFFF);i++);

    return NULL;
}

int main(void)
{
    int i = 0;
    int err;
    // use import <sys/sysinfo.h>
    // it return the number of cores available
    int nthread = get_nprocs(); 

    printf("%d", nthread);
	    
    while(i < nthread)
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        else
            printf("\n Thread created successfully\n");
	printf("\n N° threads : %d", ++i);
    }

    sleep(5);
    return 0;
}
