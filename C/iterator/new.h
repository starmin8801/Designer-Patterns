#ifndef NEW_H
#define NEW_H

#include "list.h"
#include <stdbool.h>

void *New(const void *_class, ...);
void Delete(void *_class);
void Insert(void *_list, void *_item);
void Remove(void *_list, void *_item);
// void Iterator(const void *list, Handle_FN handle_fn, ...);
void Print(void *_list, Print_FN print_fn);
void AddItemToContainer(void *_container, void *_item);
void RemoveItemFromContainer(void *_container, void *_item);
void *CreateIterator(void *_container);
void *First(const void *_iterator);
void *Current(const void *_iterator);
void *Next(const void *_iterator);
bool isDone(const void *_iterator);

#endif
