#include "iterator.h"
#include "concreteIterator.h"
#include "singleList.h"
#include "container.h"
#include "new.h"
#include <assert.h>

static void *concreteIteratorCtor(void *_self, va_list *params) {
    _ConcreteIterator *self = _self;

    self->container = va_arg(*params, void*);
    self->currentIndex = 0;
    
    return self;
}

static void *concreteIteratorDtor(void *_self) {
    _ConcreteIterator *self = _self;

    self->container = NULL;
    self->currentIndex = -1;

    return self;
}

static void *concreteIteratorFirst(const void *_self) {
    _ConcreteIterator *self = (void*)_self;
    const Container * const *container = self->container;

    assert(self->container && *container && (*container)->getItem);

    self->currentIndex = 0;
    return (*container)->getItem(self->container, self->currentIndex);
}

static void *concreteIteratorNext(const void *_self) {
    _ConcreteIterator *self = (void*)_self;
    const Container * const *container = self->container;

    assert(self->container && *container && (*container)->getItem);

    return (*container)->getItem(self->container, self->currentIndex++);
}

static bool concreteIteratorIsDone(const void *_self) {
    const _ConcreteIterator *self = _self;
    const Container * const *container = self->container;

    assert(self->container && *container && (*container)->getSize);

    if (self->currentIndex >= (*container)->getSize(self->container)) {
        return true;
    } else {
        return false;
    }
}

static void *concreteIteratorCurrentItem(const void *_self) {
    const _ConcreteIterator *self = _self;
    const Container * const *container = self->container;

    assert(self->container && *container && (*container)->getItem);

    return (*container)->getItem(self->container, self->currentIndex); 
}

static const Iterator _concreateIterator = {
    sizeof(_ConcreteIterator),
    concreteIteratorCtor,
    concreteIteratorDtor,
    concreteIteratorFirst,
    concreteIteratorNext,
    concreteIteratorIsDone,
    concreteIteratorCurrentItem
};

const void *ConcreteIterator = &_concreateIterator;
