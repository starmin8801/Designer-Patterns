#ifndef CONCRETECLASS2_H
#define CONCRETECLASS2_H

#include "abstractClass.h"

typedef struct {
    const void *abstractClass;
    void (*primitiveOperation1)(const void *_self);
    void (*primitiveOperation2)(const void *_self);
    double b;
} _ConcreteClass2;

extern const void *ConcreteClass2;

#endif
