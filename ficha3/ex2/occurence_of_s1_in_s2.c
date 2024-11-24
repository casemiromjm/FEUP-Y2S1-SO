#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Return the string str in lower
char* stringToLower(const char *str) {

    char *str_lower = strdup(str);

    for (int i = 0; str_lower[i] != '\0'; i++) {
        str_lower[i] = tolower(str_lower[i]);
    }

    return str_lower;
}

// Return the numbers of occurences of str1 in str2
int occurencesInString(const char* str1, const char* str2) {
    int counter = 0;
    const char *pos = str2;

    while ((pos = strstr(pos, str1)) != NULL) {
        counter++;
        pos++;
    }

    return counter;
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

    char* str1 = stringToLower(argv[1]);
    char* str2 = stringToLower(argv[2]);

    if (strlen(str1) > strlen(str2)) {
        printf("The string '%s' is too big to be in '%s'\n", argv[1], argv[2]);
        free(str1);
        free(str2);
        exit(EXIT_FAILURE);
    }

    int occ = occurencesInString(str1, str2);

    if (occ > 0) {
        printf("The string '%s' occurs in '%s' %d time(s)\n", argv[1], argv[2], occ);
    }
    else {
        printf("The string '%s' does not occur in '%s'\n", argv[1], argv[2]);
    }

    // free memory dinamically allocated
    free(str1);
    free(str2);

    exit(EXIT_SUCCESS);
}