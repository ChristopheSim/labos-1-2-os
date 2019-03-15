#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 50

int main() {
    char string[BUFFER_SIZE];
    char path[30];

    FILE *source_file;
    FILE *destination_file;

    source_file = fopen("../lorem_ipsum.txt", "r");
    if (source_file == NULL) {
        printf("Error read file");
        return -1;
    }
    
    int i = 0;
    while (fgets(string, BUFFER_SIZE, source_file) != NULL) {
        sprintf(path, "./calc/fork%d.txt", i);
        destination_file = fopen(path, "a");


        fclose(destination_file);
        i += 1;
    }

    fclose(source_file);
    return 0;
}

