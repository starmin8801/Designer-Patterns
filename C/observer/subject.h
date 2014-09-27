#ifndef SUBJECT_H
#define SUBJECT_H

#include <stdlib.h>
#include <stdarg.h>

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*attach)(void *_self, void *_obv);  // Observer
    void (*detach)(void *_self, void *_obv);  // Observer
    void (*notify)(const void *_self);
    void (*setstate)(void *_self, char *_st);
    char *(*getstate)(const void *_self);
} Subject;

#endif

