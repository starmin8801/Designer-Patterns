#include "proxy.h"
#include "bigImage.h"
#include "realBigImage.h"
#include "new.h"
#include <assert.h>

static void *proxyCtor(void *_self, va_list *params) {
    _Proxy *self = _self;

    self->bigImage = New(RealBigImage, va_arg(*params, char*));

    return self;
}

static void *proxyDtor(void *_self) {
    _Proxy *self = _self;

    self->bigImage = NULL;

    return self;
}

static void proxyShow(const void *_self) {
    const _Proxy *self = _self;
    const BigImage * const *bigImage = self->bigImage;

    assert(self->bigImage && *bigImage && (*bigImage)->show);

    (*bigImage)->show(self->bigImage);
}

static const BigImage _proxy = {
    sizeof(_Proxy),
    proxyCtor,
    proxyDtor,
    proxyShow
};

const void *Proxy = &_proxy;
