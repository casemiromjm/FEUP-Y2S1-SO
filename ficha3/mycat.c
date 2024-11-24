#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void printFile(char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("error: could not open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    int chars_read = fread(buffer, sizeof(char), BUFFER_SIZE, file);

    while (chars_read > 0) {
        fwrite(buffer, sizeof(char), chars_read, stdout);

        chars_read = fread(buffer, sizeof(char), BUFFER_SIZE, file);
    }

    fclose(file);   
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("Need to indicate at least 1 file\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        printFile(argv[i]);
    }

    exit(EXIT_SUCCESS);
}