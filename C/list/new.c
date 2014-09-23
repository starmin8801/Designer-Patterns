#include "new.h"
#include "abstractClass.h"
#include "list.h"

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

void Insert(void *_list, void *_item) {
    ((const _SingleList*)SingleList)->insert(_list, _item);
}

void Remove(void *_list, void *_item) {
    ((const _SingleList*)SingleList)->remove(_list, _item);
}

void Print(void *_list, Print_FN print_fn) {
    ((const _SingleList*)SingleList)->print(_list, print_fn);
}
