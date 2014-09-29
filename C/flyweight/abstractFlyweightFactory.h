#ifndef ABSTRACTFLYWEIGHTFACTORY_H
#define ABSTRACTFLYWEIGHTFACTORY_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void* (*getFlyweight)(const void *_self, const char *_key);
} AbstractFlyweightFactory;


#endif
