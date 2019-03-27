#include "functions.h"

int size_file(char path[]) {
    FILE *file;
    int size = 0;

    file = fopen(path, "r");
        if (file == NULL) {
            printf("Error read file");
            exit(-1);
        }
        else {
            // Put the cursor at the end of the file and take this position
            fseek(file, 0, SEEK_END);
            size = ftell(file);
            fclose(file);
        }
    
    return size;
}