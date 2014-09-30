#ifndef NEW_H
#define NEW_H

void *New(const void *_class, ...);
void Delete(void *_class);
void Operation(const void *_class);
void MethodA(const void *_operatorWapper);
void MethodB(const void *_operatorWapper);

#endif
