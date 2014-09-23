#ifndef LIST_H
#define LIST_H

#include <stdarg.h>
#include <stdlib.h>

typedef struct _Node {
    void *data;
    struct _Node *next;
} Node;

typedef void (*Print_FN)(void* data);

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*insert)(void *_self, void *data);
    void (*remove)(void *_self, void *data);
    void (*print)(void *_self, Print_FN print_fn);
    Node *head;
} _SingleList;

extern const void *SingleList;

#endif
