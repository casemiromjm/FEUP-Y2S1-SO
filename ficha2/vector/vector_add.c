#include "vector.h"

vector* vector_add(vector* a, vector* b) {
    return vector_new(a->x + b->x, a->y + b->y, a->z + b->z);
}