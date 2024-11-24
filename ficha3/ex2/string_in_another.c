#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* stringToLower(const char *str) {

    char *str_lower = strdup(str);

    for (int i = 0; str_lower[i] != '\0'; i++) {
        str_lower[i] = tolower(str_lower[i]);
    }

    return str_lower;
}

int stringInEachOther(char *str1, char *str2) {
    // 1 -> true, 0 -> false

    if (strlen(str1) > strlen(str2)) {
        return 0;
    }

    if (strcmp(str1, str2) == 0) {
        return 1;
    }

    int counter = 0, in = 0;

    for (int i = 0; str2[i] != '\0'; i++) {
        if (counter == strlen(str1)-1) {
            break;
        }

        if (str2[i] == str1[counter]) {
            counter++;
            in = 1;
        }

        else {
            counter = 0;
            in = 0;
        }
    }

    return in;
}

int main(int argc, char* argv[]) {

    if (argc <= 2) {
        printf("Need to input two strings\n");
        exit(EXIT_FAILURE);
    }

    else if (argc > 3) {
        printf("Too many strings\n");
        exit(EXIT_FAILURE);
    }

    char* str1_lower = stringToLower(argv[1]);
    char* str2_lower = stringTolower(argv[2]);

    if (stringInEachOther(str1_lower, str2_lower) == 1) {
        printf("The string '%s' occurs in '%s'\n", argv[1], argv[2]);
    }
    else {
        printf("The string '%s' does not occurs in '%s'\n", argv[1], argv[2]);
    }

    free(str1_lower);
    free(str2_lower);

    exit(EXIT_SUCCESS);
}