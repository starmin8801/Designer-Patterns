#include "product.h"
#include "productA.h"
#include <stdarg.h>
#include <stdio.h>

static void *productACtor(void *_self, va_list *params) {
    _ProductA *self = _self;

    return self;
}

static void *productADtor(void *_self) {
    _ProductA *self = _self;

    return self;
}

static void productAShow(const void *_self) {
    (void)_self;
    fprintf(stdout, "Product A\n");
}

static const Product _product = {
    sizeof(_ProductA),
    productACtor,
    productADtor,
    productAShow
};

const void *ProductA = &_product;
