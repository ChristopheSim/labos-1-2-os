#ifndef H_THREAD
#define H_THREAD

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void* count_letters(void* arg);

#endif /* thread */
