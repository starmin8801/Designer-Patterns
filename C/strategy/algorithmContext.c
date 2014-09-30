#include "algorithm.h"
#include "algorithmContext.h"
#include <assert.h>

static void *algorithmContextCtor(void *_self, va_list *params) {
    _AlgorithmContext *self = _self;

    self->ra = va_arg(*params, void*);

    return self;
}

static void *algorithmContextDtor(void *_self) {
    _AlgorithmContext *self = _self;

    self->ra = NULL;
    
    return self;
}

static void algorithmContextCalculate(const void *_self) {
    const _AlgorithmContext *self = _self;
    const Algorithm * const *ra = self->ra;

    assert(self->ra && *ra && (*ra)->calculate);

    (*ra)->calculate(self->ra);
}

static const Algorithm _algorithmContextCalculate = {
    sizeof(_AlgorithmContext),
    algorithmContextCtor,
    algorithmContextDtor,
    algorithmContextCalculate
};

const void *AlgorithmContext = &_algorithmContextCalculate;
