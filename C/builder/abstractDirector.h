#ifndef ABSTRACTDIRECTOR_H
#define ABSTRACTDIRECTOR_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*create)(const void *_self);
} AbstractDirector;

#endif
