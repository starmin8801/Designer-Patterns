#ifndef COUNTRY_H
#define COUNTRY_H

#include <stdarg.h>
#include <stdlib.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*setMediator)(void *_self, void *mediator);
    void (*sendMessage)(void *_self, char *message);
    void (*getMessage)(void *_self, char *message);
} Country;

#endif
