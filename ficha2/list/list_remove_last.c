#include "list.h"
#include <stddef.h>
#include <stdlib.h>

void list_remove_last(list* l) {
    node* p = l->first;
    node* previous = NULL;

    while (p->next != NULL) {
        previous = p;
        p = p->next;
    }

    previous->next = NULL;

    l->size--;
    free(p);
}