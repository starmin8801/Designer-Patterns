#ifndef CHIP_H
#define CHIP_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*show)(const void *_self);
} Chip;

#endif
