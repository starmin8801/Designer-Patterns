#ifndef NEW_H
#define NEW_H

#include "list.h"

void *New(const void *_class, ...);
void Delete(void *_class);
void Insert(void *_list, void *_item);
void Remove(void *_list, void *_item);
void Print(void *_list, Print_FN print_fn);

#endif
