#include "vector.h"
#include "list.h"

#include <stdlib.h>

struct vector {
    int size;
    struct list_head head;
};

struct bundle_node {
    struct bundle bundle;
    struct list_head list;
};

struct vector *vector_new() {
    struct vector *v = malloc(sizeof(struct vector) + 1);

    v->size = 0;
    LIST_HEAD_REINIT(v->head);

    return v;
}

int vector_size(struct vector *v) {
    return v->size;
}

bool vector_is_empty(struct vector *v) {
    return vector_size(v) == 0;
}

struct bundle vector_get(struct vector *v, int position) {
    if (v->size <= position) {
        printf("index %d out of range: size is %d\n", position, v->size);
        struct bundle error = {0,};
        return error;
    }

    struct bundle_node *node = list_first_entry(&v->head, struct bundle_node, list);
    for (int i = 0; i < position; ++i) {
        node = list_next_entry(node, list);
    }

    return node->bundle;
}

static inline struct bundle *push(struct vector *v, int where) {
    struct bundle_node *new_node = malloc(sizeof(struct bundle_node) + 1);
    struct bundle *bundle_created = &new_node->bundle;

    if (where == VECTOR_FRONT) {
        list_add(&new_node->list, &v->head); /* Add to front */
    } else {
        list_add_tail(&new_node->list, &v->head); /* Add to front */
    }

    v->size++;

    return bundle_created;
}

static inline struct bundle pop(struct vector *v, int where) {
    struct bundle_node *popped;

    if (where == VECTOR_FRONT) {
        popped = list_first_entry(&v->head, struct bundle_node, list);
    } else {
        popped = list_last_entry(&v->head, struct bundle_node, list);
    }

    struct bundle bundle_copied = popped->bundle;

    list_del(&popped->list); /* let other nodes forget this */
    free(popped);

    v->size--;

    return bundle_copied;
}

void vector_push_front(struct vector *v, struct bundle item) {
    struct bundle *pushed = push(v, VECTOR_FRONT);

    *pushed = item;
}

struct bundle vector_pop_front(struct vector *v) {
    return pop(v, VECTOR_FRONT);
}

void vector_push_back(struct vector *v, struct bundle item) {
    struct bundle *pushed = push(v, VECTOR_BACK);

    *pushed = item;
}

struct bundle vector_pop_back(struct vector *v) {
    return pop(v, VECTOR_BACK);
}

void vector_delete(struct vector *v) {
    while (v->size > 0) {
        pop(v, VECTOR_FRONT);
    }

    free(v);
}