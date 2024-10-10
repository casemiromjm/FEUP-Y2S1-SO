// returns i (a local variable) address as the pointer to an integer

#include <stdio.h>

int* get_int() {
    int i = 2;
    return &i;
}

int main(void) {

    int* p = get_int();

    printf("integer = %d\n", *p);

    return 0;
}