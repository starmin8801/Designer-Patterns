#ifndef ABSTRACTCONTEXT_H
#define ABSTRACTCONTEXT_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    char* (*getData)(const void *_self);
} AbstractContext;

#endif
