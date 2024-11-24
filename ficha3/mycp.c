#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void copyFile(const char* src_name, const char* dest_name) {
    FILE* src = fopen(src_name, "r");
    FILE* dest = fopen(dest_name, "w");

    if (src == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    else if (dest == NULL) {
        perror("Unable to handle file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    int chars_read = fread(buffer, sizeof(char), BUFFER_SIZE, src);

    while(chars_read > 0) {
        fwrite(buffer, sizeof(char), chars_read, dest);

        chars_read = fread(buffer, sizeof(char), BUFFER_SIZE, src);
    }

    fclose(src);
    fclose(dest);
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf("Need to indicate 2 files\n");
        exit(EXIT_FAILURE);
    }

    // src = argv[1];
    // dest = argv[2];

    copyFile(argv[1], argv[2]);

    exit(EXIT_SUCCESS);
}