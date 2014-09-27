#include "handle.h"
#include "concreteHandleB.h"
#include <stdlib.h>
#include <stdio.h>

static void *concreteHandleBCtor(void *_self, va_list *params) {
    _ConcreteHandleB *self = _self;

    return self;
}

static void *concreteHandleBDtor(void *_self) {
    _ConcreteHandleB *self = _self;

    self->succ = NULL;

    return self;
}

static void concreteHandleBSetSuccessor(void *_self, void *_succ) {
    _ConcreteHandleB *self = _self;

    self->succ = _succ;
}

static void *concreteHandleBGetSuccessor(const void *_self) {
    const _ConcreteHandleB *self = _self;

    return self->succ;
}

static void concreteHandleBhandleRequest(const void *_self, int request) {
    if (request >= 500 && request < 1000) {
        fprintf(stdout, "ConcreteHandleB deal with: %d\n", request);
    } else if (concreteHandleBGetSuccessor(_self) != NULL) {
        const Handle * const *succ = concreteHandleBGetSuccessor(_self);
        (*succ)->handleRequest(succ, request);
    } else {
        fprintf(stderr, "Can't deal with: %d\n", request);
    }
}

static const Handle _concreteHandleB = {
    sizeof(_ConcreteHandleB),
    concreteHandleBCtor,
    concreteHandleBDtor,
    concreteHandleBSetSuccessor,
    concreteHandleBGetSuccessor,
    concreteHandleBhandleRequest
};

const void *ConcreteHandleB = &_concreteHandleB;
