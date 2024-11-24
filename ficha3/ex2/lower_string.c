#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void stringToLower(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main(int argc, char* argv[]) {

    if (argc == 1) {
        printf("Need to input one string\n");
        exit(EXIT_FAILURE);
    }

    else if (argc > 2) {
        printf("Too many strings\n");
        exit(EXIT_FAILURE);
    }

    stringToLower(argv[1]);
    printf("%s\n", argv[1]);

    exit(EXIT_SUCCESS);
}