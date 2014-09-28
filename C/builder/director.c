#include "abstractDirector.h"
#include "director.h"
#include "builder.h"
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

static void *directorCtor(void *_self, va_list *params) {
    _Director *self = _self;

    self->builder = va_arg(*params, void*);

    return self;
}

static void *directorDtor(void *_self) {
    _Director *self = _self;

    return self;
}

static void directorCreate(const void *_self) {
    const _Director *self = _self;
    const Builder * const *builder = self->builder;

    (*builder)->buildStep1(self->builder);
    (*builder)->buildStep2(self->builder);
    (*builder)->buildStep3(self->builder);
    (*builder)->buildStep4(self->builder);
}

static const AbstractDirector _director = {
    sizeof(_Director),
    directorCtor,
    directorDtor,
    directorCreate
};

const void *Director = &_director;
