#include "new.h"
#include "abstractClass.h"
#include "factory.h"
#include "product.h"
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

void *New(const void *_class, ...) {
    const AbstractClass *class = _class;

    void *p = calloc(1, class->size);

    assert(p);
    *(const AbstractClass **)p = class;
    
    if (class->ctor) {
        va_list params;

        va_start(params, _class);
        p = class->ctor(p, &params);
        va_end(params);
    }

    return p;
}

void Delete(void *_class) {
    const AbstractClass **class = _class;

    if (_class && *class && (*class)->dtor) {
        _class = (*class)->dtor(_class);
    }

    free(_class);
}

void *CreateProduct(const void *_factory) {
    const Factory * const *factory = _factory;
    if (_factory && *factory && (*factory)->createProduct) {
        return (*factory)->createProduct(_factory);
    } else {
        return NULL;
    }
}

void Show(const void *_product) {
    const Product * const *product = _product;
    if (_product && *product && (*product)->show) {    
        (*product)->show(_product);
    }
}
