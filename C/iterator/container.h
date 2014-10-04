#ifndef CTCONTAINER_H
#define CTCONTAINER_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *self, va_list *params);
    void* (*dtor)(void *self);
    void (*add)(void *_self, void *_item);
    void (*remove)(void *_self, void *_item);
    void* (*createIterator)(void *_self);
    void* (*getItem)(const void *_self, int index);
    int (*getSize)(const void *_self);
} Container;

#endif
