#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*attach)(void *_self, void *_seed);
    void (*detach)(void *_self, void *_seed);
    void (*display)(void *_self, void *_status);
} Object;

#endif
