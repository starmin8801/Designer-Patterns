#ifndef FACTORY_H
#define FACTORY_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void* (*createProduct)(const void *_self);
} Factory;

#endif
