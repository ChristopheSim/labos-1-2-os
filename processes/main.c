#include <stdio.h>
#include <unistd.h> 

#define BUFFER_SIZE 50

/* void forkexample() 
{ 
    // child process because return value zero 
    if (fork() == 0) 
        printf("Hello from Child!\n"); 
  
    // parent process because return value non-zero. 
    else
        printf("Hello from Parent!\n"); 
}  */

int main(int argc, char *argv[]) 
{ 
    char string[BUFFER_SIZE];

    if(fork())
        sample = string;
    else if(fork())
        sample = string;
    else
        myvar = 3;

    printf("I'm %d: myvar is %d\n", getpid(), myvar);

    return 0; 
} 