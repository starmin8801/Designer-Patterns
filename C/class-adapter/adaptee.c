#include "adaptee.h"
#include <stdio.h>

static void *adapteeCtor(void *_self, va_list *params) {
    _Adaptee *self = _self;

    return self;
}

static void *adapteeDtor(void *_self) {
    _Adaptee *self = _self;

    return self;
}

static void adapteeSpecificRequest(const void *_self) {
    (void)_self;
    fprintf(stdout, "Adaptee::SpecificRequest\n");
}

static const _Adaptee _adaptee = {
    sizeof(_Adaptee),
    adapteeCtor,
    adapteeDtor,
    adapteeSpecificRequest
};

const void *Adaptee = &_adaptee;
