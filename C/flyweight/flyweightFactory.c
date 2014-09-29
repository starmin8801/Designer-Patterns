#include "abstractFlyweightFactory.h"
#include "flyweightFactory.h"
#include "new.h"
#include "singleList.h"
#include "flyweight.h"
#include "concreteFlyweight.h"
#include <stdio.h>

static void *flyweightFactoryCtor(void *_self, va_list *params) {
    _FlyweightFactory *self = _self;

    self->listFlyweight = New(SingleList);
    
    return self;
}

static void *flyweightFactoryDtor(void *_self) {
    _FlyweightFactory *self = _self;

    Delete(self->listFlyweight);
    self->listFlyweight = NULL;

    return self;
}

static void *find(const void *_flyweight, va_list *params) {
    const Flyweight * const *flyweight = _flyweight;
    const char *_key = va_arg(*params, const char*);

    if ((*flyweight)->getIntrinsicState(_flyweight) == _key) {
        return (void*)_flyweight;
    } else {
        return NULL;
    }
}

static void *flyweightFactoryGetFlyweight(const void *_self, const char *_key) {
    const _FlyweightFactory *self = _self;
    void *flyweight = Find(self->listFlyweight, find, _key);

    if (flyweight != NULL) {
        fprintf(stdout, "Already created by uses...\n");
    } else {
        flyweight = New(ConcreteFlyweight, _key);
        Insert(self->listFlyweight, flyweight);
    }

    return flyweight;
}

static const AbstractFlyweightFactory _flyweightFactory = {
    sizeof(_FlyweightFactory),
    flyweightFactoryCtor,
    flyweightFactoryDtor,
    flyweightFactoryGetFlyweight
};

const void *FlyweightFactory = &_flyweightFactory;
