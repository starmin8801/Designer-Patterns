#include "mediator.h"
#include "un.h"
#include "country.h"
#include <stdlib.h>

static void *UNCtor(void *_self, va_list *params) {
    _UN *self = _self;

    self->Japan = NULL;
    self->China = NULL;

    return self;
}

static void UNSend(void *_self, char *_message, void *_country) {
    _UN *self = _self;
    Country **country = NULL;
    
    if (self->Japan == _country) {
        country = self->China;
        (*country)->getMessage(self->China, _message);
    } else {
        country = self->Japan;
        (*country)->getMessage(self->Japan, _message);
    }
}

static void UNSetJapan(void *_self, void *_Japan) {
    _UN *self = _self;

    self->Japan = _Japan;
}

static void UNSetChina(void *_self, void *_China) {
    _UN *self = _self;

    self->China = _China;
}

static const Mediator _un = {
    sizeof(_UN),
    UNCtor,
    NULL,
    UNSend,
    UNSetJapan,
    UNSetChina
};

const void *UN = &_un;
