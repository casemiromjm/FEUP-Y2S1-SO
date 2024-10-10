#include "vector.h"

vector* vector_scale(double a, vector* v) {
    return vector_new(a * v->x, a * v->y, a * v->z);
}