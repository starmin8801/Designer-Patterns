#include "factory.h"
#include "factoryA.h"
#include "productA.h"
#include "chipA.h"
#include "new.h"
#include <stdarg.h>

static void *factoryACtor(void *_self, va_list *params){
    _FactoryA *self = _self;

    return self;
}

static void *factoryADtor(void *_self) {
    _FactoryA *self = _self;

    return self;
}

static void* factoryACreateProduct(const void *self) {
    return New(ProductA);
}

static void* factoryACreateChip(const void *self) {
    return New(ChipA);
}

static const Factory _factory = {
    sizeof(_FactoryA),
    factoryACtor,
    factoryADtor,
    factoryACreateProduct,
    factoryACreateChip
};

const void *FactoryA = &_factory;
