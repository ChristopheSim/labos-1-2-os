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
            while (fgetc(file) != EOF) {
                size++;
            }
            fclose(file);
        }
    
    return size;
}