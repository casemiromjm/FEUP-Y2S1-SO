#include "vector.h"
#include <math.h>

double vector_mod(vector* v) {
    return sqrt(v->x*v->x + v->y*v->y + v->z*v->z);
}