#include "adapter.h"
#include "target.h"
#include "adaptee.h"

static void *adapterCtor(void *_self, va_list *params) {
    _Adapter *self = _self;

    return self;
}

static void *adapterDtor(void *_self) {
    _Adapter *self = _self;

    return self;
}

static void adapterSpecificRequest(const void *_self) {
    ((const _Adaptee*)Adaptee)->specificRequest(_self);
}

static void adapterRequst(const void *_self) {
    adapterSpecificRequest(_self);
}

static const _Target _adapter = {
    sizeof(_Adapter),
    adapterCtor,
    adapterDtor,
    adapterRequst
};

const void *Adapter = &_adapter;
