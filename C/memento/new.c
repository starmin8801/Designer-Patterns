#include "new.h"
#include "abstractClass.h"
#include "abstractMemento.h"
#include "abstractOriginator.h"
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

void SetState(void *_originator, char *_sdt) {
    AbstractOriginator **originator = _originator;

    if (_originator && *originator && (*originator)->setState) {
        (*originator)->setState(_originator, _sdt);
    }
}

void PrintState(const void *_originator) {
    const AbstractOriginator * const *originator = _originator;

    if (_originator && *originator && (*originator)->printState) {
        (*originator)->printState(_originator);
    }    
}

void *CreateMemento(void *_originator) {
    AbstractOriginator **originator = _originator;

    if (_originator && *originator && (*originator)->createMemento) {
        return (*originator)->createMemento(_originator);
    } else {
        return NULL;
    }
}

void RestoreToMemento(void *_originator, void *_memento) {
    AbstractOriginator **originator = _originator;

    if (_originator && *originator && (*originator)->restoreToMemento) {
        (*originator)->restoreToMemento(_originator, _memento);
    }    
}
