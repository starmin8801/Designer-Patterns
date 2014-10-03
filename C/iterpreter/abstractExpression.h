#ifndef ABSTRACTEXPRESSION_H
#define ABSTRACTEXPRESSION_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*interpret)(const void *_self, void *_context);
} AbstractExpresion;

#endif
