#include <stdlib.h>
#include "vector.h"

vector* vector_new(double a, double b, double c) {
    vector* new_vec = (vector*)malloc(sizeof(vector));
    new_vec->x = a;
    new_vec->y = b;
    new_vec->z = c;

    return new_vec;
}