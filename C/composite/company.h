#ifndef COMPANY_H
#define COMPANY_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*add)(void *_self, void *_company);
    void (*display)(const void *_self, int depth);
} Company;

#endif
