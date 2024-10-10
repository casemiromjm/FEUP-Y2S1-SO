#include "list.h"
#include "stdio.h"

int main(void) {

    list* l = list_new();

    for (int i = 0; i <= 5; i++) {
        list_add_last(i, l);
    }

    list_print(l);

    list_add_first(10, l);
    printf("%d\n", list_get_first(l));
    list_print(l);

    list_remove_first(l);
    printf("%d\n", list_get_last(l));
    list_print(l);

    list_remove_last(l);
    list_print(l);

    list* alist = list_new_random(1, 10);
    list_print(alist);

    printf("%d\n", list_size(l));
    printf("%d\n", list_size(alist));

    return 0;
}