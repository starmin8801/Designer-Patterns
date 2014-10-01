#ifndef ABSTRACTMEMENTO_H
#define ABSTRACTMEMENTO_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*setState)(void *_self, char *_st);
    char* (*getState)(const void *_self);
} AbstractMemento;

#endif

