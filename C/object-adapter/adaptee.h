#ifndef ADAPTEE_H
#define ADAPTEE_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*specificRequest)(const void *_self);
} _Adaptee;

extern const void *Adaptee;

#endif
