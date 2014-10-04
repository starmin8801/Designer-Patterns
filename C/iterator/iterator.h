#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void* (*first)(const void *_self);
    void* (*next)(const void *_self);
    bool (*isDone)(const void *_self);
    void* (*currentItem)(const void *_self);
} Iterator;

#endif
