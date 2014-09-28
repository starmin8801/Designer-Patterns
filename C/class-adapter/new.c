#include "new.h"
#include "abstractClass.h"
#include "target.h"

#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

void *New(const void *_class, ...) {
    const AbstractClass *class = _class;

    void *p = calloc(1, class->size);

    assert(p);
    *(const AbstractClass **)p = class;
    
    if (class->ctor) {
        va_list params;

        va_start(params, _class);
        p = class->ctor(p, &params);
        va_end(params);
    }

    return p;
}

void Delete(void *_class) {
    const AbstractClass **class = _class;

    if (_class && *class && (*class)->dtor) {
        _class = (*class)->dtor(_class);
    }

    free(_class);
}

void Request(const void *_target) {
    const _Target * const *target = _target;

    if (_target && *target && (*target)->request) {
        (*target)->request(_target);
    }
}
