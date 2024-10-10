#include "list.h"
#include <stddef.h>

void list_add_first(int i, list* l) {
    node* p = node_new(i, NULL);

    if (l->size == 0) {
        l->first = p;
    } else {
        node* t = node_new(i, l->first);
        l->first = t;
    }
    
    l->size++;
}