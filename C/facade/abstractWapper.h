#ifndef ABSTRACTWAPPER_H
#define ABSTRACTWAPPER_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*methodA)(const void *_self);
    void (*methodB)(const void *_self);
} AbstractWapper;

#endif
