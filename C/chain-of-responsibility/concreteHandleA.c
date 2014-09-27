#include "handle.h"
#include "concreteHandleA.h"
#include <stdlib.h>
#include <stdio.h>

static void *concreteHandleACtor(void *_self, va_list *params) {
    _ConcreteHandleA *self = _self;

    return self;
}

static void *concreteHandleADtor(void *_self) {
    _ConcreteHandleA *self = _self;

    self->succ = NULL;

    return self;
}

static void concreteHandleASetSuccessor(void *_self, void *_succ) {
    _ConcreteHandleA *self = _self;

    self->succ = _succ;
}

static void *concreteHandleAGetSuccessor(const void *_self) {
    const _ConcreteHandleA *self = _self;

    return self->succ;
}

static void concreteHandleAhandleRequest(const void *_self, int request) {
    if (request >= 0 && request < 500) {
        fprintf(stdout, "ConcreteHandleA deal with: %d\n", request);
    } else if (concreteHandleAGetSuccessor(_self) != NULL) {
        const Handle * const *succ = concreteHandleAGetSuccessor(_self);
        (*succ)->handleRequest(succ, request);
    } else {
        fprintf(stderr, "Can't deal with: %d\n", request);
    }
}

static const Handle _concreteHandleA = {
    sizeof(_ConcreteHandleA),
    concreteHandleACtor,
    concreteHandleADtor,
    concreteHandleASetSuccessor,
    concreteHandleAGetSuccessor,
    concreteHandleAhandleRequest
};

const void *ConcreteHandleA = &_concreteHandleA;
