#include "new.h"
#include "abstractClass.h"
#include "singleList.h"
#include "subject.h"
#include "observer.h"
#include <assert.h>

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

void SetState(void *_subject, char *_st) {
    Subject **subject = _subject;

    if (_subject && *subject && (*subject)->setstate) {
        (*subject)->setstate(_subject, _st);
    }
}

void Notify(const void *_subject) {
    const Subject * const *subject = _subject;

    if (_subject && *subject && (*subject)->notify) {
        (*subject)->notify(_subject);
    }
}

void Update(void *_observer, const void *_subject) {
    Observer **observer = _observer;

    if (_observer && *observer && (*observer)->update) {
        (*observer)->update(_observer, _subject);
    }
}

void Insert(void *_list, void *_item) {
    ((const List*)SingleList)->insert(_list, _item);
}

void Remove(void *_list, void *_item) {
    ((const List*)SingleList)->remove(_list, _item);
}

void Iterator(const void *_list, Handle_FN handle_fn, ...) {
    va_list params;
    va_start(params, handle_fn);
    ((const List*)SingleList)->iterator(_list, handle_fn, &params);
    va_end(params);
}

void Print(void *_list, Print_FN print_fn) {
    ((const List*)SingleList)->print(_list, print_fn);
}
