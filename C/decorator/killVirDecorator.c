#include "fileSys.h"
#include "decorator.h"
#include "killVirDecorator.h"
#include <stdio.h>

static void *killVirDecoratorCtor(void *_self, va_list *params) {
    _KillVirDecorator *self =
        ((const FileSys*)Decorator)->ctor(_self, params);

    return self;
}

static void *killVirDecoratorDtor(void *_self) {
    _KillVirDecorator *self =
        ((const FileSys*)Decorator)->dtor(_self);

    return self;
}

static void killVirDecoratorBehavior(const void *_self) {
    (void)_self;

    fprintf(stdout, "Added Kill Virus Behavior ...\n");
}

static void killVirDecoratorOperation(const void *_self) {
    const _Decorator *decorator = _self;
    const FileSys * const *fileSys = decorator->fileSys;
    
    (*fileSys)->operation(decorator->fileSys);

    killVirDecoratorBehavior(_self);
}

static const FileSys _killVirDecorator = {
    sizeof(_KillVirDecorator),
    killVirDecoratorCtor,
    killVirDecoratorDtor,
    killVirDecoratorOperation
};

const void *KillVirDecorator = &_killVirDecorator;
