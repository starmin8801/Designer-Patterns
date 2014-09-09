#include "concreteClass1.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

static void *concreteClass1Ctor(void *_self, va_list *params) {
    _ConcreteClass1 *self = _self;
    const char *description = va_arg(*params, const char *);

    (*(AbstractClass **)self)->description = calloc(1, strlen(description) + 1);
    assert((*(AbstractClass **)self)->description);
    strncpy((*(AbstractClass **)self)->description, description, strlen(description) + 1);
    
    self->a = va_arg(*params, int);

    return self;
}

static void *concreteClass1Dtor(void *_self) {
    _ConcreteClass1 *self = _self;

    if (NULL != (*(AbstractClass *)self)->description) {
        free((*(AbstractClass **)self)->description);
        (*(AbstractClass **)self)->description = NULL;
    }
    self->a = 0;

    return self;
}

static void concreteClass1PrimitiveOperation1(const void *_self) {
    if (NULL != (*(const AbstractClass * const *)_self)->description) {
        fprintf(stdout, "%s\n", (*(const AbstractClass * const *)_self)->description);
    }
}

static void concreteClass1PrimitiveOperation2(const void *_self) {
    const _ConcreteClass1 *self = _self;

    fprintf(stdout, "%d\n", self->a);
}

static void concreteClass1TemplateMethod(const void* _self) {
    concreteClass1PrimitiveOperation1(_self);
    concreteClass1PrimitiveOperation2(_self);
}

static AbstractClass _concreteClass1 = {
    sizeof(_ConcreteClass1),
    concreteClass1Ctor,
    concreteClass1Dtor,
    concreteClass1TemplateMethod,
    NULL
};

const void *ConcreteClass1 = &_concreteClass1;
