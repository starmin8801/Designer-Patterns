#ifndef OBSERVER_H
#define OBSERVER_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void* _self, va_list *params);
    void* (*dtor)(void *_self);
    void (*update)(void *_self, const void *sub);  // Subject
    void (*printinfo)(const void *_self);
} Observer;

#endif
