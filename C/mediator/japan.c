#include "country.h"
#include "japan.h"
#include "mediator.h"
#include <assert.h>
#include <stdio.h>

static void japanSetMediator(void *_self, void *_mediator) {
    _Japan *self = _self;

    self->mediator = _mediator;
}

static void japanSendMessage(void *_self, char *_message) {
    _Japan *self = _self;
    Mediator **mediator = self->mediator;

    assert(self->mediator && *mediator && (*mediator)->send);

    (*mediator)->send(self->mediator, _message, _self);
}

static void japanGetMessage(void *_self, char *_message) {
    (void)_self;

    fprintf(stdout, "日本收到信息: %s\n", _message);
}

static const Country _japan = {
    sizeof(_Japan),
    NULL,
    NULL,
    japanSetMediator,
    japanSendMessage,
    japanGetMessage
};

const void *Japan = &_japan;
