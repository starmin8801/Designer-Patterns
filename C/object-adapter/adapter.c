#include "adapter.h"
#include "target.h"
#include "adaptee.h"
#include <assert.h>

static void *adapterCtor(void *_self, va_list *params) {
    _Adapter *self = _self;
    self->ade = va_arg(*params, void*);

    return self;
}

static void *adapterDtor(void *_self) {
    _Adapter *self = _self;

    return self;
}

static void adapterRequst(const void *_self) {
    const _Adapter *self = _self;
    const _Adaptee * const *ade = self->ade;
    
    assert(self->ade && *ade && (*ade)->specificRequest);
    (*ade)->specificRequest(_self);
}

static const _Target _adapter = {
    sizeof(_Adapter),
    adapterCtor,
    adapterDtor,
    adapterRequst
};

const void *Adapter = &_adapter;
