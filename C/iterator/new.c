#include "new.h"
#include "abstractClass.h"
#include "singleList.h"
#include "container.h"
#include "iterator.h"
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

/*
void Iterator(const void *_list, Handle_FN handle_fn, ...) {
    va_list params;
    va_start(params, handle_fn);
    ((const List*)SingleList)->iterator(_list, handle_fn, &params);
    va_end(params);
}
*/

void Print(void *_list, Print_FN print_fn) {
    ((const List*)SingleList)->print(_list, print_fn);
}

void AddItemToContainer(void *_container, void *_item) {
    Container **container = _container;

    if (_container && *container && (*container)->add) {
        (*container)->add(_container, _item);
    }
}

void RemoveItemFromContainer(void *_container, void *_item) {
    Container **container = _container;

    if (_container && *container && (*container)->remove) {
        (*container)->remove(_container, _item);
    }
}

void *CreateIterator(void *_container) {
    Container **container = _container;

    assert (_container && *container && (*container)->createIterator);

    return (*container)->createIterator(_container);
}

void *First(const void *_iterator) {
    const Iterator * const *iterator = _iterator;

    assert(_iterator && *iterator && (*iterator)->first);

    return (*iterator)->first(_iterator);
}

void *Current(const void *_iterator) {
    const Iterator * const *iterator = _iterator;

    assert(_iterator && *iterator && (*iterator)->currentItem);

    return (*iterator)->currentItem(_iterator);
}

void *Next(const void *_iterator) {
    const Iterator * const *iterator = _iterator;

    assert(_iterator && *iterator && (*iterator)->next);

    return (*iterator)->next(_iterator);
}

bool isDone(const void *_iterator) {
    const Iterator * const *iterator = _iterator;

    assert(_iterator && *iterator && (*iterator)->isDone);

    return (*iterator)->isDone(_iterator);
}
