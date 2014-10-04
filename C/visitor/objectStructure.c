#include "object.h"
#include "objectStructure.h"
#include "seed.h"
#include "singleList.h"
#include "new.h"
#include <assert.h>

static void *objectStructureCtor(void *_self, va_list *params) {
    _ObjectStructure *self = _self;

    self->listSeed = New(SingleList);

    return self;
}

static void *objectStructureDtor(void *_self) {
    _ObjectStructure *self = _self;

    Delete(self->listSeed);
    self->listSeed = NULL;

    return self;
}

static void objectStructureAttach(void *_self, void *_seed) {
    _ObjectStructure *self = _self;

    Insert(self->listSeed, _seed);
}

static void objectStructureDetach(void *_self, void *_seed) {
    _ObjectStructure *self = _self;

    Remove(self->listSeed, _seed);
}

static void accept(const void *_seed, va_list *params) {
    Seed **seed =(void*) _seed;
    void *status = va_arg(*params, void*);

    assert(_seed && *seed && (*seed)->accept);

    (*seed)->accept((void*)_seed, status);
}

static void objectStructureDisplay(void *_self, void *_status) {
    _ObjectStructure *self = _self;
    
    Iterator(self->listSeed, accept, _status);
}

static const Object _objectStructure = {
    sizeof(_ObjectStructure),
    objectStructureCtor,
    objectStructureDtor,
    objectStructureAttach,
    objectStructureDetach,
    objectStructureDisplay
};

const void *ObjectStructure = &_objectStructure;
