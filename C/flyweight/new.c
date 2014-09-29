#include "new.h"
#include "abstractClass.h"
#include "singleList.h"
#include "abstractFlyweightFactory.h"
#include "flyweightFactory.h"
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

void *Find(const void *_list, Find_FN find_fn, ...) {
    va_list params;
    va_start(params, find_fn);
    void *node = ((const List*)SingleList)->find(_list, find_fn, &params);
    va_end(params);

    return node;
}

void Print(void *_list, Print_FN print_fn) {
    ((const List*)SingleList)->print(_list, print_fn);
}

void *GetFlyweight(const void *_factory, const char *_key) {
    return ((const AbstractFlyweightFactory*)FlyweightFactory)->getFlyweight(_factory, _key);
}
