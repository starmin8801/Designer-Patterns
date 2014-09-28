#include "target.h"
#include <stdio.h>

static void *targetCtor(void *_self, va_list *params) {
    _Target *self = _self;

    return self;
}

static void *targetDtor(void *_self) {
    _Target *self = _self;

    return self;
}

static void targetRequest(const void *_self) {
    (void)_self;
    fprintf(stdout, "Target::Request\n");
}

static const _Target _target = {
    sizeof(_Target),
    targetCtor,
    targetDtor,
    targetRequest
};

const void *Target = &_target;
