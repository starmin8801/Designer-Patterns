#include "prototype.h"
#include "concretePrototype.h"
#include "new.h"

static void *concretePrototypeCtor(void *_self, va_list *params) {
    _ConcretePrototype *self = _self;

    self->item = va_arg(*params, void*);

    return _self;
}

static void *concretePrototypeDtor(void *_self) {
    _ConcretePrototype *self = _self;

    return _self;
}

static void *concretePrototypeClone(const void *_self) {
    const _ConcretePrototype *self = _self;

    return New(ConcretePrototype, self->item);
}

static const Prototype _prototype = {
    sizeof(_ConcretePrototype),
    concretePrototypeCtor,
    concretePrototypeDtor,
    concretePrototypeClone
};

const void *ConcretePrototype = &_prototype;
