#include "subject.h"
#include "datasubject.h"
#include "new.h"
#include "singleList.h"
#include "observer.h"
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>

static void *dataSubjectCtor(void *_self, va_list *params) {
    _DataSubject *self = _self;

    self->obvs = New(SingleList);

    return self;
}

static void *dataSubjectDtor(void *_self) {
    _DataSubject *self = _self;

    Delete(self->obvs);
    self->obvs = NULL;

    return self;
}

static void dataSubjectAttach(void *_self, void *_obv) {
    _DataSubject *self = _self;
    Insert(self->obvs, _obv);
}

static void dataSubjectDetach(void *_self, void *_obv) {
    _DataSubject *self = _self;
    Remove(self->obvs, _obv);
}

static void update(void *_obv, va_list *params) {
    Observer **obv = _obv;
    
    void *sub = va_arg(*params, void*);
    assert(_obv && *obv && (*obv)->update);
    (*obv)->update(_obv, sub);
}

static void dataSubjectNotify(const void *_self) {
    const _DataSubject *self = _self;
    Iterator(self->obvs, update, _self);
}

static void dataSubjectSetState(void *_self, char *_st) {
    _DataSubject *self = _self;
    self->st = _st;
}

static char *dataSubjectGetState(const void *_self) {
    const _DataSubject *self = _self;
    return self->st;
}

static const Subject dataSubject = {
    sizeof(_DataSubject),
    dataSubjectCtor,
    dataSubjectDtor,
    dataSubjectAttach,
    dataSubjectDetach,
    dataSubjectNotify,
    dataSubjectSetState,
    dataSubjectGetState
};

const void *DataSubject = &dataSubject;
