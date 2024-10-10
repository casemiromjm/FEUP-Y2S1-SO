#include "list.h"

int list_get_first(list *l) {
    /* assumes list l is not empty */
    return l->first->val;
}