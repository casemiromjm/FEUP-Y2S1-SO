#include "list.h"
#include <stdio.h>

void list_print(list* l) {

    printf("[");

    node* p = l->first;

    for (int i = 0; i < l->size - 1; i++) {
        printf("%d, ", p->val);
        p = p->next;
    }

    printf("%d]\n", p->val);
}