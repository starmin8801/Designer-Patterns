#include "observer.h"
#include "sheetobserver.h"
#include "subject.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static void* sheetObserverCtor(void *_self, va_list *params) {
    _SheetObserver *self = _self;

    self->sub = va_arg(*params, void*);
    
    const Subject **sub = self->sub;
    
    assert(self->sub && *sub && (*sub)->attach);
    (*sub)->attach(self->sub, _self);
    
    return self;
}

static void *sheetObserverDtor(void *_self) {
    _SheetObserver *self = _self;
    const Subject **sub = self->sub;

    assert(self->sub && *sub && (*sub)->detach);
    (*sub)->detach(self->sub, _self);
    self->sub = NULL;
    
    return self;
}

static void sheetObserverPrintInfo(const void *_self) {
    const _SheetObserver *self = _self;
    
    fprintf(stdout, "SheetObserver: %s\n", self->st);
}

static void sheetObserverUpdate(void *_self, const void *_sub) {
    _SheetObserver *self = _self;
    const Subject * const *sub = _sub;
    
    assert(_sub && *sub && (*sub)->getstate);
    self->st = (*sub)->getstate(_sub);

    sheetObserverPrintInfo(_self);
}

static const Observer _sheetObserver = {
    sizeof(_SheetObserver),
    sheetObserverCtor,
    sheetObserverDtor,
    sheetObserverUpdate,
    sheetObserverPrintInfo
};

const void *SheetObserver = &_sheetObserver;
