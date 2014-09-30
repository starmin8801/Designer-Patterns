#ifndef NEW_H
#define NEW_H

void *New(const void *_class, ...);
void Delete(void *_class);
void SetStep(void *_work, int step);
void Operation(void *_work);

#endif
