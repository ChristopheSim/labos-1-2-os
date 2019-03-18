#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_frequencies();

int main() {
     // Number of cara at take
    FILE *source_file, *destination_file;

    // Calcul of the file's size
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
        int cara = 0;
        while (cara < BUFFER_SIZE) {
            string[cara] = fgetc(source_file);
            cara ++;
        }

        // Formating to create the path file
        sprintf(name_file, "fork%d", i);
        sprintf(path, "./calc/%s.txt", name_file);

        destination_file = fopen(path, "a");

        // Code Juju

        fclose(destination_file);
        i += 1;                
    }

    fclose(source_file);
    sort_frequencies();

    return 0;
}

void sort_frequencies() {
    FILE *frequencies_table, *fork_file;
    char path_fork_file[30], name_fork_file[15], string[10];
    int frequencies[26] = { 0 };

    frequencies_table = fopen("./frequenciesTable.txt", "w");

    int fork = 0;
    while (fork < NUMBER_OF_FORK) {
        sprintf(name_fork_file, "fork%d", fork);
        sprintf(path_fork_file, "./calc/%s.txt", name_fork_file);

        fork_file = fopen(path_fork_file, "r");
        
        while (fgets(string, 10, fork_file) != NULL) {
            char frequency[strlen(string) - 1];
            // Remove carriage return
            if (string[strlen(string) - 1] == '\n') {
                string[strlen(string) - 1] = '\0';
            }
            
            frequency[strlen(frequency) - 1] = '\0';

            // Recover the frequency
            for (int i = 0; i < strlen(string) - 2; i++) {
                frequency[i] = string[2+i];
            }

            frequencies[string[0] - 97] += atoi(frequency);
        }

        fclose(fork_file);
        fork ++;
    }

    // Print the frequencies in the file
    char str[15];
    for (int i = 0; i < 26; i++) {
        sprintf(str, "%c:%d\n", i+97, frequencies[i]);
        fputs(str, frequencies_table);
    }

    fclose(frequencies_table);

}