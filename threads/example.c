#include<stdio.h>
#include<string.h>
#include<pthread.h> //for threads manipulation
#include<stdlib.h>
#include<unistd.h>
#include<sys/sysinfo.h> //look nbr of threads

long int size(char *addr)
{
	FILE *fichier;
	long int sfile;

	fichier=fopen (addr,"rb");

	if(fichier)
	{
		fseek (fichier, 0, SEEK_END);
		sfile=ftell (fichier);
		fclose (fichier);
	}
	return sfile;
}

void* doSomeThing(void *arg)
{
    unsigned long i = 0;
    pthread_t id = pthread_self();

    printf("\nN° process : [%d]",getpid());
    printf("\nID thread : [%d]\n",id);

    for(i=0; i<(0xFFFFFFFF);i++);

    return NULL;
}

int computesizethread(long int sfile, int nthread)
{
	long int ratio = sfile / (long int)nthread;
	return (int)ratio;
}

int main(void)
{
    int i = 0;
    int err;
    
    // use import <sys/sysinfo.h>
    // it return the number of cores available
    int nthread = get_nprocs(); 
    printf("\nnbr thread : [%d]", nthread);
    
    long int sfile = size("../lorem_ipsum.txt");
    printf("\nsize file : [%li]", sfile);

    int sthread = computesizethread(sfile, nthread);
    printf("\nsize thread : [%d]\n", sthread);
    
    pthread_t tid[nthread];

    while(i < nthread)
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\nerror creating thread : %s", strerror(err));
        else
            printf("\nThread created successfully");
	printf("\nID thread : [%d]", tid[i]);
	printf("\nN° threads : [%d]", ++i);
    }

    sleep(5);
    return 0;
}
