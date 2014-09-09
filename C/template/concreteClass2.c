#include "concreteClass2.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

static void *concreteClass2Ctor(void *_self, va_list *params) {
    _ConcreteClass2 *self = _self;
    const char *description = va_arg(*params, const char *);

    (*(AbstractClass **)self)->description = calloc(1, strlen(description) + 1);
    assert((*(AbstractClass **)self)->description);
    strncpy((*(AbstractClass **)self)->description, description, strlen(description) + 1);
    self->b = va_arg(*params, double);

    return self;
}

static void *concreteClass2Dtor(void *_self) {
    _ConcreteClass2 *self = _self;

    if (NULL != (*(AbstractClass **)self)->description) {
        free((*(AbstractClass **)self)->description);
        (*(AbstractClass **)self)->description = NULL;
    }
    self->b = 0;

    return self;
}

static void concreteClass2PrimitiveOperation1(const void *_self) {
    if (NULL != (*(const AbstractClass * const *)_self)->description) {
        fprintf(stdout, "%s\n", (*(const AbstractClass **)_self)->description);
    }    
}

static void concreteClass2PrimitiveOperation2(const void *_self) {
    const _ConcreteClass2 *self = _self;

    fprintf(stdout, "%f\n", self->b);
}

static void concreteClass2TemplateMethod(const void* _self) {
    concreteClass2PrimitiveOperation1(_self);
    concreteClass2PrimitiveOperation2(_self);
}

static AbstractClass _concreteClass2 = {
    sizeof(_ConcreteClass2),
    concreteClass2Ctor,
    concreteClass2Dtor,
    concreteClass2TemplateMethod,
    NULL
};

const void *ConcreteClass2 = &_concreteClass2;
