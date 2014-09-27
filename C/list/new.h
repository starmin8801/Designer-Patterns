#ifndef NEW_H
#define NEW_H

#include "list.h"
#include <stdarg.h>

void *New(const void *_class, ...);
void Delete(void *_class);
void Insert(const void *_list, void *_item);
void Remove(const void *_list, void *_item);
void Iterator(const void *_list, Handle_FN handle_fn, ...);
void Print(const void *_list, Print_FN print_fn);

#endif
