#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_FORK 10
#define MIN_CARA 200

void sort_frequencies(char *paths);

int main() {
    int FILE_SIZE = 0; //size of the source file
    int BUFFER_SIZE = 0; //number of cara at take
    FILE *source_file;
    FILE *destination_file;

    //Calcul of the file's size
    source_file = fopen("../lorem_ipsum.txt", "r");
    if (source_file == NULL) {
        printf("Error read file");
        exit(-1);
    }
    else {
        while (fgetc(source_file) != EOF) {
            FILE_SIZE++;
        }
        fclose(source_file);
    }

    if (FILE_SIZE <= MIN_CARA) {
        BUFFER_SIZE = FILE_SIZE;
    }
    else if (FILE_SIZE > MIN_CARA) {
        BUFFER_SIZE = FILE_SIZE/NUMBER_OF_FORK;
    }

    char string[BUFFER_SIZE];
    char path[30];
    char name_file[30];
    char paths[NUMBER_OF_FORK][20];

    source_file = fopen("../lorem_ipsum.txt", "r");
    if (source_file == NULL) {
        printf("Error read file");
        exit(-1);
    }

    // Calcul of the frequencies table
    int i = 0;
    while (i < NUMBER_OF_FORK) {
        // Take the n*BUFFER_SIZE cara for computing
        int cara = 0;
        while (cara < BUFFER_SIZE) {
            string[cara] = fgetc(source_file);
            cara ++;
        }

        // Formating to create the path file and save the name file created
        sprintf(name_file, "fork%d", i);
        sprintf(paths[i], "fork%d", i);
        sprintf(path, "./calc/%s.txt", name_file);

        destination_file = fopen(path, "a");

        //Code Juju

        //Just for testing// fputs(string, destination_file);

        fclose(destination_file);
        i += 1;                
    }

    fclose(source_file);
    return 0;
}

void sort_frequencies(char *paths) {
    
}


