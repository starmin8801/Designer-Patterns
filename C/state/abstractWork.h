#ifndef ABSTRACTWORK_H
#define ABSTRACTWORK_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    int (*getStep)(const void *_self);
    void (*setStep)(void *_self, int _step);
    void (*setState)(void *_self, void *_state);
    void (*operation)(void *_self);
} AbstractWork;


#endif
