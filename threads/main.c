#include"./thread.h"

#include<stdio.h>
#include<pthread.h> //for threads manipulation
#include<sys/sysinfo.h> //look nbr of threads
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

struct thread_param {
	FILE *fichier;
	int startchar;
	int nchar;
	int result[26];
};

long int size(FILE *f)
{
    long int sfile;
    if (f)
    {
        fseek (f, 0, SEEK_END);
        sfile=ftell (f);
    }
    return sfile;
}

int main(void)
{
    int err;
    FILE *fichier;
    fichier = fopen ("../lorem_ipsum.txt","rb");

    // use import <sys/sysinfo.h>
    // it return the number of cores available
    int nthread = get_nprocs();
	if ( nthread < 0 )
	{
		nthread = 1;
	}

    long int sfile = size(fichier);
    //printf("\nsize file : [%li]", sfile);

    int sthread = (int) sfile / nthread;
    //printf("\nsize thread : [%d]\n", sthread);

    pthread_t tid[nthread];

    struct thread_param thread_args[nthread];

    for(int i=0; i<nthread; i++)
    {
	// set arguments for the threads
	thread_args[i].fichier = fichier; //set fichier
	thread_args[i].startchar = i*sthread;
	thread_args[i].nchar = sthread;

	// create the threads with the arguments
    err = pthread_create(&(tid[i]), NULL, &count_letters, &(thread_args[i]));
	// informations about the thread
	//printf("\nID thread : [%d]", tid[i]);
	//printf("\nN° threads : [%d]", ++i);
    }

    // wait to kill all the threads
    for(int i=0; i<nthread; i++)
    {
	pthread_join(tid[i], NULL);
	printf("Kill thread : [%d]\n", i);
    }

    // manipulate received value from threads
    int result[26] = {0};
    for(int i=0; i<26; i++)
    {
	    for(int j=0; j<nthread; j++)
	    {
		    result[i] += thread_args[j].result[i];
	    }
    	    printf("Result [%d] : %d\n", i, result[i]);
    }

    fclose(fichier);

    return 0;
}
