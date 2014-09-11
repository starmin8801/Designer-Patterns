#include "factory.h"
#include "factoryB.h"
#include "productB.h"
#include "chipB.h"
#include "new.h"
#include <stdarg.h>

static void *factoryBCtor(void *_self, va_list *params){
    _FactoryB *self = _self;

    return self;
}

static void *factoryBDtor(void *_self) {
    _FactoryB *self = _self;

    return self;
}

static void* factoryBCreateProduct(const void *self) {
    return New(ProductB);
}

static void* factoryBCreateChip(const void *self) {
    return New(ChipB);
}

static const Factory _factory = {
    sizeof(_FactoryB),
    factoryBCtor,
    factoryBDtor,
    factoryBCreateProduct,
    factoryBCreateChip
};

const void *FactoryB = &_factory;
