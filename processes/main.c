#include "./src/config.h"
#include "./src/functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {    
     // Number of cara at take
    FILE *source_file;

    // Calcul of the file's size
    FILE_SIZE = size_file("../lorem_ipsum.txt");    

    // Decision of the buffer size
    if (FILE_SIZE <= MIN_CARA) {
        BUFFER_SIZE = FILE_SIZE;
        NUMBER_OF_FORK = 1;
    }
    else if (FILE_SIZE > MIN_CARA) {
        BUFFER_SIZE = FILE_SIZE/NUMBER_OF_FORK;
    }


    // Calcul of the frequencies table
    char string[BUFFER_SIZE], path[30], name_file[30];

    source_file = fopen("../lorem_ipsum.txt", "r");
    if (source_file == NULL) {
        printf("Error read file");
        exit(-1);
    }

    int i = 0;
    while (i < NUMBER_OF_FORK) {
        // Take the n*BUFFER_SIZE cara for computing
        fread(string, sizeof(char), BUFFER_SIZE, source_file);

        // Formating to create the path file
        sprintf(name_file, "fork%d", i);
        sprintf(path, "./calc/%s.txt", name_file);

        if (fork() == 0) {
            count_letters(path, string);
            return 0;
        }
        i ++;                
    }

    for(int i=0; i < NUMBER_OF_FORK; i++) {
        /* printf("%d\n", getpid()); */
        pid_t cpid = wait(NULL);
        /* printf("%d\n", cpid); */
    }

    fclose(source_file);
    sort_frequencies();

    printf("C'est fini !!");

    return 0;
}