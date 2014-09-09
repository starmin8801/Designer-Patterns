#ifndef NEW_H
#define NEW_H

void *New(const void *_class, ...);
void Delete(void *_class);
void *CreateProduct(const void *_factory);
void Show(const void *product);

#endif
