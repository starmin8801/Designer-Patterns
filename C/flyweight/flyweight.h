#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*operation)(void *_self, char *_extrinsicState);
    char *(*getIntrinsicState)(const void *_self);
} Flyweight;

#endif
