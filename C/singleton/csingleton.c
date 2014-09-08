#include "csingleton.h"
#include <stdlib.h>

static void *csingletonCtor(void *_self) {
    _CSingleton *self = _self;

    self->instance = _self;

    return self;
}

static void *csingletonDtor(void *_self) {
    _CSingleton *self = _self;

    self->instance = NULL;

    return self;
}

static void *csingletonCreateInstance(void *_self) {
    _CSingleton *self = _self;

    self->instance = _self;

    return self;
}

static const _CSingleton _csingleton = {
    csingletonCtor, csingletonDtor, csingletonCreateInstance, NULL
};

const void *CSingleton = &_csingleton;

void *GetInstance(void) {
    if (NULL == ((_CSingleton*)CSingleton)->instance) {
        return csingletonCtor(CSingleton);
    } else {
        return ((_CSingleton*)CSingleton)->instance;
    }
}
