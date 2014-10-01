#include "new.h"
#include "abstractClass.h"
#include "mediator.h"
#include "country.h"
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

void SetJanpa(void *_mediator, void *_Japan) {
    Mediator **mediator = _mediator;

    if (_mediator && *mediator && (*mediator)->setJapan) {
        (*mediator)->setJapan(_mediator, _Japan);
    }
}

void SetChina(void *_mediator, void *_China) {
    Mediator **mediator = _mediator;

    if (_mediator && *mediator && (*mediator)->setChina) {
        (*mediator)->setChina(_mediator, _China);
    }
}

void SetMediator(void *_country, void *_mediator) {
    Country **country = _country;

    if (_country && *country && (*country)->setMediator) {
        (*country)->setMediator(_country, _mediator);
    }
}

void SendMessage(void *_country, char *_message) {
    Country **country = _country;

    if (_country && *country && (*country)->sendMessage) {
        (*country)->sendMessage(_country, _message);
    }
}
