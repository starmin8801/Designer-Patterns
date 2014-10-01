#ifndef NEW_H
#define NEW_H

void *New(const void *_class, ...);
void Delete(void *_class);
void SetState(void *_originator, char *_sdt);
void PrintState(const void *_originator);
void *CreateMemento(void *_originator);
void RestoreToMemento(void *_originator, void *_memento);

#endif
