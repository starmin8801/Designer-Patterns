#include "command.h"
#include "abstractReciever.h"
#include "writeCommand.h"
#include "new.h"
#include <stdio.h>

static void *writeCommandCtor(void *_self, va_list *params) {
    _WriteCommand *self = _self;

    self->reciever = va_arg(*params, void*);

    return self;
}

static void *writeCommandDtor(void *_self) {
    _WriteCommand *self = _self;

    Delete(self->reciever);
    self->reciever = NULL;

    return self;
}

static void writeCommandExecute(const void *_self) {
    fprintf(stdout, "Write Command ...\n");

    const _WriteCommand *self = _self;
    AbstractReciever **reciever = self->reciever;

    (*reciever)->action(self->reciever);
}

static const Command _writeCommand = {
    sizeof(_WriteCommand),
    writeCommandCtor,
    writeCommandDtor,
    writeCommandExecute
};

const void *WriteCommand = &_writeCommand;
