#include <stdio.h>

int main() {
    int i;
    char msg[] = "Hello World"; // cstring

    for (i = 0; i < sizeof(msg); i++) // sizeof = memory size?
        printf("%p: %c <--> %p: %c\n", &(msg[i]), msg[i], msg + i, *(msg + i));
    return 0;
}