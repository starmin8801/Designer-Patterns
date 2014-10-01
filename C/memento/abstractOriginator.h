#ifndef ABSTRACTORIGINATOR_H
#define ABSTRACTORIGINATOR_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void* (*createMemento)(void *_self);
    void (*restoreToMemento)(void *_self, void *_mt);
    char* (*getState)(const void *_self);
    void (*setState)(void *_self, char *_sdt);
    void (*printState)(const void *_self);
} AbstractOriginator;

#endif
