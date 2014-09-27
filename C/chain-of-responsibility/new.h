#ifndef NEW_H
#define NEW_H

void *New(const void *_class, ...);
void Delete(void *_class);
void SetSuccessor(void *_handle, void *_succ);
void HandleRequest(void *_handle, int request);

#endif
