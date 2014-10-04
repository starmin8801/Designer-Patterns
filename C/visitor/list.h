#ifndef LIST_H
#define LIST_H

#include <stdarg.h>
#include <stdlib.h>

typedef void (*Print_FN)(void* data);
typedef void (*Handle_FN)(const void *node, va_list *params);

typedef struct {
    size_t size;
    void* (*ctor)(void *_self, va_list *params);
    void* (*dtor)(void *_self);
    void (*insert)(const void *_self, void *data);
    void (*remove)(const void *_self, void *data);
    void (*iterator)(const void *_self, Handle_FN handle_fn, va_list *params);
    void (*print)(const void *_self, Print_FN print_fn);
} List;

#endif
