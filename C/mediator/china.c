#include "country.h"
#include "china.h"
#include "mediator.h"
#include <assert.h>
#include <stdio.h>

static void chinaSetMediator(void *_self, void *_mediator) {
    _China *self = _self;

    self->mediator = _mediator;
}

static void chinaSendMessage(void *_self, char *_message) {
    _China *self = _self;
    Mediator **mediator = self->mediator;

    assert(self->mediator && *mediator && (*mediator)->send);

    (*mediator)->send(self->mediator, _message, _self);
    
}

static void chinaGetMessage(void *_self, char *_message) {
    (void)_self;

    fprintf(stdout, "中国收到消息: %s\n", _message);
}

static const Country _china = {
    sizeof(_China),
    NULL,
    NULL,
    chinaSetMediator,
    chinaSendMessage,
    chinaGetMessage
};

const void *China = &_china;
