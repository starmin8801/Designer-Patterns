#ifndef ABSTRACTRECIEVER_H
#define ABSTRACTRECIEVER_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*action)(const void *_self);
} AbstractReciever;

#endif
