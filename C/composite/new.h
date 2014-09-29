#ifndef NEW_H
#define NEW_H

#include "list.h"

void *New(const void *_class, ...);
void Delete(void *_class);
void Add(void *_comp, void *_leaf);
void Display(const void *_comp, int depth);
void Insert(void *_list, void *_item);
void Remove(void *_list, void *_item);
void Iterator(const void *list, Handle_FN handle_fn, ...);

#endif
