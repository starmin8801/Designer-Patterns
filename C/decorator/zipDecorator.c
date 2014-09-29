#include "fileSys.h"
#include "decorator.h"
#include "zipDecorator.h"
#include <stdio.h>

static void *zipDecoratorCtor(void *_self, va_list *params) {
    _ZipDecorator *self =
        ((const FileSys*)Decorator)->ctor(_self, params);

    return self;
}

static void *zipDecoratorDtor(void *_self) {
    _ZipDecorator *self =
        ((const FileSys*)Decorator)->dtor(_self);

    return self;
}

static void zipDecoratorBehavior(const void *_self) {
    (void)_self;

    fprintf(stdout, "Added zip Behavior ...\n");
}


static void zipDecoratorOperation(const void *_self) {
    const _Decorator *decorator = _self;
    const FileSys * const *fileSys =  decorator->fileSys;
    
    (*fileSys)->operation(decorator->fileSys);
  
    zipDecoratorBehavior(_self);
}

static const FileSys _zipDecorator = {
    sizeof(_ZipDecorator),
    zipDecoratorCtor,
    zipDecoratorDtor,
    zipDecoratorOperation
};

const void *ZipDecorator = &_zipDecorator;
