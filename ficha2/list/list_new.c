#include "list.h"
#include <stdlib.h>
#include <stddef.h>

list *list_new()
{
    list *l = (list *)malloc(sizeof(list));
    l->size = 0;
    l->first = NULL;
    return l;
}