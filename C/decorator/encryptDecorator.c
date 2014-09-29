#include "fileSys.h"
#include "decorator.h"
#include "encryptDecorator.h"
#include <stdio.h>

static void *encryptDecoratorCtor(void *_self, va_list *params) {
    _EncryptDecorator *self =
        ((const FileSys*)Decorator)->ctor(_self, params);

    return self;
}

static void *encryptDecoratorDtor(void *_self) {
    _EncryptDecorator *self =
        ((const FileSys*)Decorator)->dtor(_self);

    return self;
}

static void encryptDecoratorBehavior(const void *_self) {
    (void)_self;

    fprintf(stdout, "Added Encrypt Behavior ...\n");
}


static void encryptDecoratorOperation(const void *_self) {
    const _Decorator *decorator = _self;
    const FileSys * const *fileSys = decorator->fileSys;
    
    (*fileSys)->operation(decorator->fileSys);
    
    encryptDecoratorBehavior(_self);
}

static const FileSys _encryptDecorator = {
    sizeof(_EncryptDecorator),
    encryptDecoratorCtor,
    encryptDecoratorDtor,
    encryptDecoratorOperation
};

const void *EncryptDecorator = &_encryptDecorator;
