#include <stdio.h>

#include "vector.h"

void test_vector_as_list() {
    vector_t *v = vector_new();

    vector_push_back(v, (bundle_t){.int_v = 1});
    vector_push_back(v, (bundle_t){.int_v = 2});
    vector_push_back(v, (bundle_t){.int_v = 3});

    for (int i = 0; i < vector_size(v); ++i) {
        printf("%d\n", vector_get(v, i).int_v);
    }
}

void test_vector_as_stack() {
    vector_t *v = vector_new();

    vector_push_back(v, (bundle_t){.int_v = 1});
    vector_push_back(v, (bundle_t){.int_v = 2});
    vector_push_back(v, (bundle_t){.int_v = 3});

    while (!vector_is_empty(v)) {
        printf("%d\n", vector_pop_back(v).int_v);
    }
}

void test_vector_as_queue() {
    vector_t *v = vector_new();

    vector_push_back(v, (bundle_t){.int_v = 1});
    vector_push_back(v, (bundle_t){.int_v = 2});
    vector_push_back(v, (bundle_t){.int_v = 3});

    while (!vector_is_empty(v)) {
        printf("%d\n", vector_pop_front(v).int_v);
    }
}
