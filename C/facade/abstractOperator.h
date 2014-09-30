#ifndef ABSTRACTOPERATOR_H
#define ABSTRACTOPERATOR_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*operation)(const void *_self);
} AbstractOperator;

#endif
