#ifndef NEW_H
#define NEW_H

void *New(const void *_class, ...);
void Delete(void *_class);
void *Clone(const void *_prototype);

#endif
