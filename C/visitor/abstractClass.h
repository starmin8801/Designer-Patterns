#ifndef ABSTRACTCLASS_H
#define ABSTRACTCLASS_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*templateMethod)(const void *_self);
    char *description;
} AbstractClass;

#endif
