#include "./src/config.h"
#include "./src/functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {    
    FILE *source_file;

    FILE_SIZE = size_file("../lorem_ipsum.txt");    

    // Decision of the buffer size
    if (FILE_SIZE <= MIN_CARA) {
        BUFFER_SIZE = FILE_SIZE;
        NUMBER_OF_FORK = 1;
    }
    else if (FILE_SIZE > MIN_CARA) {
        BUFFER_SIZE = FILE_SIZE/NUMBER_OF_FORK;
    }
 
 
    char string[BUFFER_SIZE], path[30], name_file[30];

    source_file = fopen("../lorem_ipsum.txt", "r");
    if (source_file == NULL) {
        printf("Error read file");
        exit(-1);
    }

    int i = 0;
    while (i < NUMBER_OF_FORK) {
        // Take the BUFFER_SIZE cara for the fork
        fread(string, sizeof(char), BUFFER_SIZE, source_file);

        // Formating to create the fork path file
        sprintf(name_file, "fork%d", i);
        sprintf(path, "./calc/%s.txt", name_file);

        if (fork() == 0) {
            count_letters(path, string);
            return 0;
        }

        i ++;                
    }

    fclose(source_file);
    
    // Wait that all forks finished
    for(int i=0; i < NUMBER_OF_FORK; i++) {
        wait(NULL);
    }

    sort_frequencies();

    // Delete fork files
    for (int j = 0; j < NUMBER_OF_FORK; j++) {
        sprintf(name_file, "fork%d", j);
        sprintf(path, "./calc/%s.txt", name_file);
        remove(path);
    }

    printf("C'est fini !!\n");

    return 0;
}