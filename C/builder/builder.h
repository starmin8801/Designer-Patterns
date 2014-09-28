#ifndef BUILDER_H
#define BUILDER_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*buildStep1)(const void *_self);
    void (*buildStep2)(const void *_self);
    void (*buildStep3)(const void *_self);
    void (*buildStep4)(const void *_self);
} Builder;


#endif
