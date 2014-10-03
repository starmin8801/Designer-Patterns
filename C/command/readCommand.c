#include "command.h"
#include "abstractReciever.h"
#include "readCommand.h"
#include "new.h"
#include <stdio.h>

static void *readCommandCtor(void *_self, va_list *params) {
    _ReadCommand *self = _self;

    self->reciever = va_arg(*params, void*);

    return self;
}

static void *readCommandDtor(void *_self) {
    _ReadCommand *self = _self;

    Delete(self->reciever);
    self->reciever = NULL;

    return self;
}

static void readCommandExecute(const void *_self) {
    fprintf(stdout, "Read Command ...\n");

    const _ReadCommand *self = _self;
    AbstractReciever **reciever = self->reciever;

    (*reciever)->action(self->reciever);
}

static const Command _readCommand = {
    sizeof(_ReadCommand),
    readCommandCtor,
    readCommandDtor,
    readCommandExecute
};

const void *ReadCommand = &_readCommand;
