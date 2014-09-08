#ifndef CONCRETECLASS1_H
#define CONCRETECLASS1_H

#include "abstractClass.h"

typedef struct {
    const void *abstractClass;
    void (*primitiveOperation1)(const void *_self);
    void (*primitiveOperation2)(const void *_self);
    int a;
} _ConcreteClass1;

extern const void *ConcreteClass1;

#endif
