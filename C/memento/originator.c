#include "abstractOriginator.h"
#include "originator.h"
#include "new.h"
#include "abstractMemento.h"
#include "memento.h"
#include <stdio.h>
#include <assert.h>

static void *originatorCtor(void *_self, va_list *params) {
    _Originator *self = _self;

    self->sdt = va_arg(*params, char*);
    self->memento = 0;

    return self;
}

static void *originatorDtor(void *_self) {
    _Originator *self = _self;

    self->sdt = NULL;
    self->memento = 0;

    return self;    
}

static void *originatorCreateMemento(void *_self) {
    _Originator *self = _self;

    return New(Memento, self->sdt);
}

static void originatorRestoreToMemento(void *_self, void *_memento) {
    _Originator *self = _self;
    AbstractMemento **memento = _memento;

    assert(_memento && *memento && (*memento)->getState);

    self->sdt = (*memento)->getState(_memento);
}

static char *originatorGetState(const void *_self) {
    const _Originator *self = _self;

    return self->sdt;
}

static void originatorSetState(void *_self, char *_sdt) {
    _Originator *self = _self;

    self->sdt = _sdt;
}

static void originatorPrintState(const void *_self) {
    const _Originator *self = _self;

    fprintf(stdout, "%s\n", self->sdt);
}

static const AbstractOriginator _originator = {
    sizeof(_Originator),
    originatorCtor,
    originatorDtor,
    originatorCreateMemento,
    originatorRestoreToMemento,
    originatorGetState,
    originatorSetState,
    originatorPrintState
};

const void *Originator = &_originator;
