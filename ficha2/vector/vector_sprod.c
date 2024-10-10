#include "vector.h"

double vector_sprod(vector* v, vector* u) {
    return (v->x * u->x) + (v->y * u->y) + (v->z * u->z);
}