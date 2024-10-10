#include <stdio.h>

int main() {

    int i, j, *p, *q;
    i = 5;
    p = &i; // p = i memory address
    printf("p=%p\n", p);
    *p = 7; // i memory address = 7
    j = 3;
    p = &j; // p = j memory address
    q = p; // q = j memory address
    printf("i=%d, j=%d, p=%p, q=%p\n", i, j, p, q);
    p = &i; // p = i memory address
    printf("i=%d, j=%d, p=%p, q=%p\n", i, j, p, q);
    *q = 2; // j memory = 2
    printf("i=%d, j=%d, p=%p, q=%p\n", i, j, p, q);

    return 0;
}