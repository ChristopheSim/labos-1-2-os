#include "functions.h"

void count_letters(char path[], char string[]) {
    FILE *file_frequency;
    int frequencies[26] = { 0 };

    for(int i = 0; i < strlen(string); i++) {
        frequencies[string[i] - 'a'] += 1;
    }

    file_frequency = fopen(path, "w");

    // Print the frequencies in the file
    char str[15];
    for (int i = 0; i < 26; i++) {
        sprintf(str, "%c:%d\n", i + 'a', frequencies[i]);
        fputs(str, file_frequency);
    }
    
    fclose(file_frequency);
}