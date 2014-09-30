#include "new.h"
#include "abstractClass.h"
#include "abstractWork.h"
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>

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

void SetStep(void *_work, int step) {
    AbstractWork **work = _work;

    if (_work && *work && (*work)->setStep) {
        (*work)->setStep(_work, step);
    }
}

void Operation(void *_work) {
    AbstractWork **work = _work;

    if (_work && *work && (*work)->operation) {
        (*work)->operation(_work);
    }
}
