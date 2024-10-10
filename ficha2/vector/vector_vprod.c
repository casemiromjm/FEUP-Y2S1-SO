#include "vector.h"

vector* vector_vprod(vector* v, vector* u) {
    return vector_new(v->y*u->z - v->z*u->y, v->z*u->x - v->x*u->z, v->x*u->y - v->y*u->x);
}