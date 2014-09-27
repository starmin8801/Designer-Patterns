#include "new.h"
#include "factory.h"
#include "productA.h"
#include "productB.h"
#include <stdlib.h>
#include <stdarg.h>

static void *factoryCtor(void *_self, va_list *params) {
    _Factory *self = _self;

    return self;
}

static void *factoryDtor(void *_self) {
    _Factory *self = _self;

    return self;
}

static void* factoryCreateProduct(const void *_self, PRODUCT_TYPE productType) {
    void *product = NULL;
    
    switch(productType) {
        case PRODUCT_A:
            product = New(ProductA);
            break;
        case PRODUCT_B:
            product = New(ProductB);
            break;
        default:
            break;
    }

    return product;
}

static const _Factory _factory = {
    sizeof(_Factory),
    factoryCtor,
    factoryDtor,
    factoryCreateProduct
};

const void *Factory = &_factory;
