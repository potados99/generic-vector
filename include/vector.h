#ifndef GENERIC_VECTOR_VECTOR_H
#define GENERIC_VECTOR_VECTOR_H

#include <stdbool.h>

#include "types.h"

#define VECTOR_FRONT 0
#define VECTOR_BACK 1

typedef struct vector vector_t;

struct vector *vector_new();

int vector_size(struct vector *v);
bool vector_is_empty(struct vector *v);

struct bundle vector_get(struct vector *v, int position);

void vector_push_front(struct vector *v, struct bundle item);
struct bundle vector_pop_front(struct vector *v);

void vector_push_back(struct vector *v, struct bundle item);
struct bundle vector_pop_back(struct vector *v);

void vector_delete(struct vector *v);

#endif //GENERIC_VECTOR_VECTOR_H
