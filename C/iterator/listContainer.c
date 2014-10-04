#include "listContainer.h"
#include "list.h"
#include "singleList.h"
#include "concreteIterator.h"
#include "container.h"
#include "new.h"
#include <assert.h>

static void *listContainerCtor(void *_self, va_list *params) {
    _ListContainer *self = _self;

    self->list = New(SingleList);

    return self;
}

static void *listContainerDtor(void *_self) {
    _ListContainer *self = _self;

    Delete(self->list);
    self->list = NULL;

    return self;
}

static void listContainerAdd(void *_self, void *_item) {
    _ListContainer *self = _self;

    Insert(self->list, _item);
}

static void listContainerRemove(void *_self, void *_item) {
    _ListContainer *self = _self;

    Remove(self->list, _item);
}

static void *listContainerCreateIterator(void *_self) {
    return New(ConcreteIterator, _self);
}

static void *listContainerGetItem(const void *_self, int index) {
    const _ListContainer *self = _self;
    const List * const *list = self->list;

    assert(self->list && *list && (*list)->getItem);

    return (*list)->getItem(self->list, index);
}

static int listContainerGetSize(const void *_self) {
    const _ListContainer *self = _self;
    const List * const *list = self->list;

    assert(self->list && *list && (*list)->getSize);

    return (*list)->getSize(self->list);
}

static const Container _listContainer = {
    sizeof(_ListContainer),
    listContainerCtor,
    listContainerDtor,
    listContainerAdd,
    listContainerRemove,
    listContainerCreateIterator,
    listContainerGetItem,
    listContainerGetSize
};

const void *ListContainer = &_listContainer;
