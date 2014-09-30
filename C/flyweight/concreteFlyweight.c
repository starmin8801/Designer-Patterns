#include "flyweight.h"
#include "concreteFlyweight.h"
#include <stdio.h>

static void *concreteFlyweightCtor(void *_self, va_list *params) {
    _ConcreteFlyweight *self = _self;

    self->intrinsicState = va_arg(*params, char*);

    fprintf(stdout, "ConcreteFlyweight Build ... %s\n", self->intrinsicState);
    
    return self;
}

static void *concreteFlyweightDtor(void *_self) {
    _ConcreteFlyweight *self = _self;

    self->intrinsicState = NULL;

    return self;
}

static void concreteFlyweightOperation(void *_self, char *_extrinsicState) {
    _ConcreteFlyweight *self = _self;

    fprintf(stdout, "内部[%s] 外部[%s]\n", self->intrinsicState, _extrinsicState);
}

static char *concreteFlyweightGetIntrinsicState(const void *_self) {
    const _ConcreteFlyweight *self = _self;

    return self->intrinsicState;
}

static const Flyweight _concreteFlyweight = {
    sizeof(_ConcreteFlyweight),
    concreteFlyweightCtor,
    concreteFlyweightDtor,
    concreteFlyweightOperation,
    concreteFlyweightGetIntrinsicState    
};

const void *ConcreteFlyweight = &_concreteFlyweight;
