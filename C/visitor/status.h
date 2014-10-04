#ifndef STATUS_H
#define STATUS_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*visitSeedA)(const void *_self, void *_elm);
    void (*visitSeedB)(const void *_self, void *_elm);
} Status;

#endif
