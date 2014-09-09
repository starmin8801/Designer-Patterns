#ifndef NEW_H
#define NEW_H

void *NewFactory(const void *_class, ...);
void *NewProduct(const void *_class, ...);
void Delete(void *_class);
void *CreateProduct(const void *_factory, int productType);
void Show(const void *product);

#endif
