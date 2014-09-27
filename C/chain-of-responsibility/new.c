#include "new.h"
#include "abstractClass.h"
#include "handle.h"
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

void SetSuccessor(void *_handle, void *_succ) {
    Handle **handle = _handle;

    if (_handle && *handle && (*handle)->setSuccessor) {
        (*handle)->setSuccessor(_handle, _succ);
    }
}

void HandleRequest(void *_handle, int request) {
    Handle **handle = _handle;

    if (_handle && *handle && (*handle)->handleRequest) {
        (*handle)->handleRequest(_handle, request);
    }
}
