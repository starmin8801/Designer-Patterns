#ifndef TARGET_H
#define TARGET_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*request)(const void *_self);
} _Target;

extern const void *Target;

#endif
