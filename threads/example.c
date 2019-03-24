#include<stdio.h>
#include<string.h>
#include<pthread.h> //for threads manipulation
#include<stdlib.h>
#include<unistd.h>
#include<sys/sysinfo.h> //look nbr of threads

struct thread_param {
	FILE *fichier;
	int startchar;
	int nchar;
};

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

void* count_letters(void* arg)
{	
    // TO DO
    struct thread_param* tp = (struct thread_param*) arg;
    /*
    int freq[26] = { 0 };

    // read part of the file
    for (int i=0; i < tp->nchar; i++)
    {
	    // read char startchar+i
    }
    */

    char *buffer = malloc(tp->nchar + 1);
    fseek(tp->fichier, tp->startchar, SEEK_SET);
    int len = fread(buffer, 1, tp->nchar, tp->fichier);
    *(buffer+len) = '\0';

    printf("%s\n", buffer);
}

void* doSomeThing(void* arg)
{
    struct thread_param* tp = (struct thread_param*) arg;

    unsigned long i = 0;
    pthread_t id = pthread_self();

    printf("\nN° process : [%d]",getpid());
    printf("\nID thread : [%d]",id);
    printf("\nstartchar : [%d]\n", tp->startchar);

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

    struct thread_param thread_args[nthread];
	
    FILE *fichier;
    fichier = fopen ("../lorem_ipsum.txt","rb");

    while(i < nthread)
    {
	// set arguments for the threads
	thread_args[i].fichier = fichier; //set fichier
	thread_args[i].startchar = i*sthread;
	thread_args[i].nchar = sthread;
	
	// create the threads with the arguments
        err = pthread_create(&(tid[i]), NULL, &count_letters, &(thread_args[i]));
        if (err != 0)
            printf("\nerror creating thread : %s", strerror(err));
        else
            printf("\nThread created successfully");
	printf("\nID thread : [%d]", tid[i]);
	printf("\nN° threads : [%d]", ++i);
    }

    i = 0;
    while(i < nthread)
    {
	// wait to kill all the threads
	pthread_join(tid[i++], NULL);
	printf("\nKill thread : [%d]", i);
    }

    fclose(fichier);

    sleep(5);
    return 0;
}
