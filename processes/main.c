#include "./src/config.h"
#include "./src/functions.h"
#include <stdio.h>
#include <stdlib.h>

int main() {    
    FILE *source_file, *destination_file;

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
    size_t ok_read = 0;
    while (i < NUMBER_OF_FORK) {
        ok_read = fread(string, sizeof(char), BUFFER_SIZE, source_file);
        
        // Formating to create the path file
        sprintf(name_file, "fork%d", i);
        sprintf(path, "./calc/%s.txt", name_file);

        destination_file = fopen(path, "a");
    }
    else {
        wait(NULL);
    }
        fclose(destination_file);
        i += 1;                
    }
    fclose(source_file);
    sort_frequencies();

    return 0;
}