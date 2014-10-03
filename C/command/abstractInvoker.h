#ifndef ABSTRACTINVOKER_H
#define ABSTRACTINVOKER_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*notify)(const void *_self);
    void (*addCmd)(void *_self, void *_pcmd);
    void (*delCmd)(void *_self, void *_pcmd);
} AbstractInvoker;

#endif
