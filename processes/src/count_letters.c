#include "functions.h"

void count_letters(char path[], char string[]) {
    FILE *file_frequency;
    int frequencies[26] = { 0 };

    // https://rosettacode.org/wiki/Letter_frequency#C
    for(int i = 0; i < strlen(string); i++) {
        if ('a' <= string[i] && 'z' >= string[i]) {
            frequencies[string[i] - 'a']++;
        }
        else if ('A' <= string[i] && 'Z' >= string[i]) {
            frequencies[string[i] - 'A']++;
        }
    }

    file_frequency = fopen(path, "w");
    if (file_frequency == NULL) {
        printf("Error read file");
        exit(-1);
    }

    // Print the frequencies in the fork file
    char str[15];
    for (int i = 0; i < 26; i++) {
        sprintf(str, "%c:%d\n", i + 'a', frequencies[i]);
        fputs(str, file_frequency);
    }

    fclose(file_frequency);
}