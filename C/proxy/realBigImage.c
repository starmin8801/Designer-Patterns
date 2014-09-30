#include "bigImage.h"
#include "realBigImage.h"
#include <stdio.h>

static void* realBigImageCtor(void *_self, va_list *params) {
    _RealBigImage *self = _self;

    self->name = va_arg(*params, char *);

    return self;
}

static void* realBigImageDtor(void *_self) {
    _RealBigImage *self = _self;

    self->name = NULL;

    return self;
}

static void realBigImageShow(const void *_self) {
    const _RealBigImage *self = _self;

    fprintf(stdout, "Show big image : %s\n", self->name);
}

static const BigImage _realBigImage = {
    sizeof(_RealBigImage),
    realBigImageCtor,
    realBigImageDtor,
    realBigImageShow
};

const void *RealBigImage = &_realBigImage;
