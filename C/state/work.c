#include "work.h"
#include "state.h"
#include "abstractWork.h"
#include "new.h"
#include <stdlib.h>
#include <assert.h>

static void *workCtor(void *_self, va_list *params) {
    _Work *self = _self;

    self->state = va_arg(*params, void*);
    self->step = 0;

    return self;
}

static void *workDtor(void *_self) {
    _Work *self = _self;

    self->state = NULL;
    self->step = 0;

    return self;
}

static int workGetStep(const void *_self) {
    const _Work *self = _self;

    return self->step;
}

static void workSetStep(void *_self, int _step) {
    _Work *self = _self;

    self->step = _step;
}

static void workSetState(void *_self, void *_state) {
    _Work *self = _self;
    
    Delete(self->state);
    self->state = _state;
}

static void workOperation(void *_self) {
    _Work *self = _self;
    State **state = self->state;

    assert(self->state && *state && (*state)->operation);

    (*state)->operation(self->state, _self);
}

static const AbstractWork _work = {
    sizeof(_Work),
    workCtor,
    workDtor,
    workGetStep,
    workSetStep,
    workSetState,
    workOperation
};

const void *Work = &_work;
