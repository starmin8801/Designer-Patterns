#ifndef DECORATOR_H
#define DECORATOR_H

typedef struct {
    const void *_;
    void *fileSys;
} _Decorator;

extern const void *Decorator;

#endif
