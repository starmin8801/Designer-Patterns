#ifndef NEW_H
#define NEW_H

#include "list.h"

void *New(const void *_class, ...);
void Delete(void *_class);
void Insert(void *_list, void *_item);
void Remove(void *_list, void *_item);
void Iterator(const void *list, Handle_FN handle_fn, ...);
void *Find(const void *_list, Find_FN Find_FN, ...);
void Print(void *_list, Print_FN print_fn);
void *GetFlyweight(const void *_factory, const char *_key);
void Operation(void *_flyweight, char *_extrinsicState);

#endif
