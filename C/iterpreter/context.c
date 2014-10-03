#include "abstractContext.h"
#include "context.h"

static void *contextCtor(void *_self, va_list *params) {
    _Context *self = _self;

    self->data = va_arg(*params, char*);

    return self;
}

static void *contextDtor(void *_self) {
    _Context *self = _self;

    self->data = NULL;

    return self;
}

static char *contextGetData(const void *_self) {
    const _Context *self = _self;

    return self->data;
}

static const AbstractContext _context = {
    sizeof(_Context),
    contextCtor,
    contextDtor,
    contextGetData
};

const void *Context = &_context;
