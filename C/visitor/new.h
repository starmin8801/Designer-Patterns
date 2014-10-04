#ifndef NEW_H
#define NEW_H

#include "list.h"

void *New(const void *_class, ...);
void Delete(void *_class);
void Insert(void *_list, void *_item);
void Remove(void *_list, void *_item);
void Iterator(const void *list, Handle_FN handle_fn, ...);
void Print(void *_list, Print_FN print_fn);
void Attach(void *_obj, void *_seed);
void Detach(void *_obj, void *_seed);
void Display(void *_obj, void *_status);

#endif
