#include "functions.h"

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