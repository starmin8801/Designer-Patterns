#include "abstractMemento.h"
#include "memento.h"

static void *mementoCtor(void *_self, va_list *params) {
    _Memento *self = _self;

    self->st = va_arg(*params, char*);

    return self;
}

static void *mementoDtor(void *_self) {
    _Memento *self = _self;

    self->st = NULL;

    return self;
}

static void mementoSetState(void *_self, char *_st) {
    _Memento *self = _self;

    self->st = _st;
}

static char *mementoGetState(const void *_self) {
    const _Memento *self = _self;

    return self->st;
}

static AbstractMemento _memento = {
    sizeof(_Memento),
    mementoCtor,
    mementoDtor,
    mementoSetState,
    mementoGetState
};

const void *Memento = &_memento;
