#ifndef COMPUTER_H
#define COMPUTER_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*installOS)(const void *_self, const void *_os);
} Computer;

#endif
