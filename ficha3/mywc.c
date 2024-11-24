#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

void countCharacters(FILE *file) {
    int counter = -1;
    char c;

    while ( (c = fgetc(file)) != EOF ) {
        counter++;
    }

    printf("%d\n", counter);
    rewind(file);
}

void countWords(FILE *file) {
    int counter = 0;
    char c;
    int inWord = 0;     // flag (1 -> in a word, 0 -> not in a word)

    while ( (c = fgetc(file)) != EOF) {
        if (isspace(c)) {
            inWord = 0;
        }
        else if (!isspace(c) && inWord == 0) {
            inWord = 1;
            counter++;
        }
    }

    printf("%d\n", counter);
    rewind(file);
}

void countLines(FILE *file) {

    // getline function works good on POSIX systems, like linux and macOS

    int counter = 0;
    ssize_t read;
    size_t size = 0;
    char* line = NULL;

    while(( read = getline(&line, &size, file)) != -1) {
        counter++;
    }

    printf("%d\n", counter);
    free(line);
    rewind(file);
}

int main(int argc, char* argv[]) {

    if (argc < 3) {
        printf("Usage: %s -[c|w|l] filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // src = argv[2]

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        perror("Not possible to open the file");
        exit(EXIT_FAILURE);
    }

    char opt;
    while ( (opt = getopt(argc, argv, "cwl")) != -1) {
        switch(opt) {
            case 'c':
                // count characters
                countCharacters(file);
                break;
            case 'w':
                // count words
                countWords(file);
                break;
            case 'l':
                // count lines
                countLines(file);
                break;
            case '?':
                printf("Invalid option\n");
                fclose(file);
                exit(EXIT_FAILURE);
            default:
                abort();
        }
    }

    fclose(file);
    exit(EXIT_SUCCESS);
}