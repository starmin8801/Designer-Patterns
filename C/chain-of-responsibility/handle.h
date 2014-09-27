#ifndef HANDLE_H
#define HANDLE_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*setSuccessor)(void *_self, void *succ);
    void *(*getSuccessor)(const void *_self);
    void (*handleRequest)(const void *_self, int request);
} Handle;


#endif
