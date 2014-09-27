#include "handle.h"
#include "concreteHandleC.h"
#include <stdlib.h>
#include <stdio.h>

static void *concreteHandleCCtor(void *_self, va_list *params) {
    _ConcreteHandleC *self = _self;

    return self;
}

static void *concreteHandleCDtor(void *_self) {
    _ConcreteHandleC *self = _self;

    self->succ = NULL;

    return self;
}

static void concreteHandleCSetSuccessor(void *_self, void *_succ) {
    _ConcreteHandleC *self = _self;

    self->succ = _succ;
}

static void *concreteHandleCGetSuccessor(const void *_self) {
    const _ConcreteHandleC *self = _self;

    return self->succ;
}

static void concreteHandleChandleRequest(const void *_self, int request) {
    if (request >= 1000 && request < 2000) {
        fprintf(stdout, "ConcreteHandleC deal with: %d\n", request);
    } else if (concreteHandleCGetSuccessor(_self) != NULL) {
        const Handle * const *succ = concreteHandleCGetSuccessor(_self);
        (*succ)->handleRequest(succ, request);
    } else {
        fprintf(stderr, "Can't deal with: %d\n", request);
    }
}

static const Handle _concreteHandleC = {
    sizeof(_ConcreteHandleC),
    concreteHandleCCtor,
    concreteHandleCDtor,
    concreteHandleCSetSuccessor,
    concreteHandleCGetSuccessor,
    concreteHandleChandleRequest
};

const void *ConcreteHandleC = &_concreteHandleC;
