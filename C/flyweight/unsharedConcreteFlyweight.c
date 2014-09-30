#include "flyweight.h"
#include "unsharedConcreteFlyweight.h"
#include <stdio.h>

static void *unsharedConcreteFlyweightCtor(void *_self, va_list *params) {
    _UnsharedConcreteFlyweight *self = _self;

    fprintf(stdout, "UnsharedConcreteFlyweight Build ...\n");
    
    return self;
}

static void *unsharedConcreteFlyweightDtor(void *_self) {
    _UnsharedConcreteFlyweight *self = _self;

    return self;
}

static void unsharedConcreteFlyweightOperation(void *_self, char *_extrinsicState) {
    (void)_self;

    fprintf(stdout, "不共享的具体Flyweight 外部[%s]\n", _extrinsicState);
}

static const Flyweight _unsharedConcreteFlyweight = {
    sizeof(_UnsharedConcreteFlyweight),
    unsharedConcreteFlyweightCtor,
    unsharedConcreteFlyweightDtor,
    unsharedConcreteFlyweightOperation,
    NULL
};

const void *UnsharedConcreteFlyweight = &_unsharedConcreteFlyweight;
