#include "product.h"
#include "productB.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static void *productBCtor(void *_self, va_list *params) {
    _ProductB *self = _self;

    return self;
}

static void *productBDtor(void *_self) {
    _ProductB *self = _self;

    return self;
}

static void productBShow(const void *_self) {
    (void)_self;
    fprintf(stdout, "Product B\n");
}

static const Product _product = {
    sizeof(_ProductB),
    productBCtor,
    productBDtor,    
    productBShow
};

const void *ProductB = &_product;
