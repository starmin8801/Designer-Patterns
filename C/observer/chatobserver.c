#include "observer.h"
#include "chatobserver.h"
#include "subject.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static void* chatObserverCtor(void *_self, va_list *params) {
    _ChatObserver *self = _self;

    self->sub = va_arg(*params, void*);
    
    const Subject **sub = self->sub;
    
    assert(self->sub && *sub && (*sub)->attach);
    (*sub)->attach(self->sub, _self);
    
    return self;
}

static void *chatObserverDtor(void *_self) {
    _ChatObserver *self = _self;
    const Subject **sub = self->sub;

    assert(self->sub && *sub && (*sub)->detach);
    (*sub)->detach(self->sub, _self);    
    self->sub = NULL;
                
    return self;
}

static void chatObserverPrintInfo(const void *_self) {
    const _ChatObserver *self = _self;
    
    fprintf(stdout, "ChatObserver: %s\n", self->st);
    
}

static void chatObserverUpdate(void *_self, const void *_sub) {
    _ChatObserver *self = _self;
    const Subject * const *sub = _sub;
    
    assert(_sub && *sub && (*sub)->getstate);
    self->st = (*sub)->getstate(_sub);

    chatObserverPrintInfo(_self);
}

static const Observer _chatObserver = {
    sizeof(_ChatObserver),
    chatObserverCtor,
    chatObserverDtor,
    chatObserverUpdate,
    chatObserverPrintInfo
};

const void *ChatObserver = &_chatObserver;
