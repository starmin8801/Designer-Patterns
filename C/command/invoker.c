#include "abstractInvoker.h"
#include "invoker.h"
#include "new.h"
#include "singleList.h"
#include "command.h"

static void *invokerCtor(void *_self, va_list *params) {
    _Invoker *self = _self;

    self->cmd = va_arg(*params, void*);
    self->cmdList = New(SingleList);

    return self;
}

static void *invokerDtor(void *_self) {
    _Invoker *self = _self;

    self->cmd = NULL;
    Delete(self->cmdList);
    self->cmdList = NULL;

    return self;
}

static void execute(void *_cmd, va_list *params) {
    Command **cmd = _cmd;

    (*cmd)->execute(_cmd);
}

static void invokerNotify(const void *_self) {
    const _Invoker *self = _self;

    Iterator(self->cmdList, execute);
}

static void invokerAddCmd(void *_self, void *_pcmd) {
    _Invoker *self = _self;

    Insert(self->cmdList, _pcmd);
}

static void invokerDelCmd(void *_self, void *_pcmd) {
    _Invoker *self = _self;

    Remove(self->cmdList, _pcmd);
}

static const AbstractInvoker _invoker = {
    sizeof(_Invoker),
    invokerCtor,
    invokerDtor,
    invokerNotify,
    invokerAddCmd,
    invokerDelCmd
};

const void *Invoker = &_invoker;
