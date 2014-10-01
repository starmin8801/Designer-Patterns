#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*send)(void *_self, char *message, void *_country);
    void (*setJapan)(void *_self, void *_Janpa);
    void (*setChina)(void *_self, void *_China);
} Mediator;

#endif
