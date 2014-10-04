#ifndef CONCRETEITERATOR_H
#define CONCRETEITERATOR_H

typedef struct {
    const void *_;
    void *container;
    int currentIndex;
} _ConcreteIterator;

extern const void *ConcreteIterator;

#endif
