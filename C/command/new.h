#ifndef NEW_H
#define NEW_H

#include "list.h"

void *New(const void *_class, ...);
void Delete(void *_class);
void Insert(void *_list, void *_item);
void Remove(void *_list, void *_item);
void Iterator(const void *list, Handle_FN handle_fn, ...);
void Print(void *_list, Print_FN print_fn);
void AddCmd(void *_inv, void *_cmd);
void DelCmd(void *_inv, void *_cmd);
void Notify(const void *_inv);

#endif
