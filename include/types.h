#ifndef GENERIC_VECTOR_TYPES_H
#define GENERIC_VECTOR_TYPES_H

#include <stdbool.h>

struct list_head {
    struct list_head *next, *prev;
};

typedef struct bundle {
    bool    bool_v;
    short   short_v;
    int     int_v;
    long    long_v;
    char    char_v;
    char    *str_v;
    void    *any_v;
} bundle_t;


#endif //GENERIC_VECTOR_TYPES_H
