#include "fileSys.h"
#include "myFileSys.h"
#include "decorator.h"
#include <stdio.h>


static void *decoratorCtor(void *_self, va_list *params) {
    _Decorator *self =
        ((const FileSys*)MyFileSys)->ctor(_self, params);

    self->fileSys = va_arg(*params, void*);

    return self;
}

static void *decoratorDtor(void *_self) {
    _Decorator *self =
        ((const FileSys*)MyFileSys)->dtor(_self);

    return self;
}

static void decoratorOperation(const void *_self) {
    ((const FileSys*)MyFileSys)->operation(_self);    
}

static const FileSys _decorator = {
    sizeof(_Decorator),
    decoratorCtor,
    decoratorDtor,
    decoratorOperation
};

const void *Decorator = &_decorator;
