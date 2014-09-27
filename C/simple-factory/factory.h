#ifndef FACTORY_H
#define FACTORY_H

#include <stdlib.h>
#include <stdarg.h>

typedef enum {
    PRODUCT_A,
    PRODUCT_B
} PRODUCT_TYPE;

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void* (*createProduct)(const void *_self, PRODUCT_TYPE productType);
} _Factory;

extern const void *Factory;

#endif
