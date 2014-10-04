#include "list.h"
#include "singleList.h"
#include "new.h"
#include <stdlib.h>

static void *singleListCtor(void *_self, va_list *params) {
    _SingleList *self = _self;

    self->head = (Node*)calloc(1, sizeof(Node));
    self->size = 0;
    
    return self;
}

static void *singleListDtor(void *_self) {
    _SingleList *self = _self;
    Node **p = &self->head;

    while ((*p) != NULL) {
        Node *node = *p;
        *p = node->next;
        free(node);
    }

    self->size = -1;
    
    return self;    
}

static void singleListInsert(const void *_self, void *data) {
    _SingleList *self = (void*)_self;
    Node *node = (Node*)calloc(1, sizeof(Node));

    Node **p = (Node **)&self->head;
    for (; (*p) != NULL; p = &(*p)->next) {
        ;
    }

    node->data = data;
    node->next = *p;
    *p = node;

    ++self->size;
}

static void singleListRemove(const void *_self, void *data) {
    _SingleList *self = (void*)_self;
    Node **p = (Node **)&self->head;

    while ((*p) != NULL) {
        Node *node = *p;
        if (node->data == data) {
            *p = node->next;
        } else {
            p = &(*p)->next;
        }
    }

    --self->size;
}

static void singleListIterator(const void *_self, Handle_FN handle_fn, va_list *params) {
    const _SingleList *self = _self;
    Node **p = &self->head->next;

    for (; (*p) != NULL; p = &(*p)->next) {
        va_list args;
        va_copy(args, *params);        
        handle_fn((*p)->data, &args);
        va_end(args);
    }
}

static void *singleListGetItem(const void *_self, int index) {
    const _SingleList *self = _self;
    Node **p = &self->head->next;

    int i = 0;
    for (; i < index; ++i) {
        p = &(*p)->next;
    }

    return (*p)->data;
}

static int singleListGetSize(const void *_self) {
    const _SingleList *self = _self;

    return self->size;
}

static void singleListPrint(const void *_self, Print_FN print_fn) {
    const _SingleList *self = _self;
    Node **p = &self->head->next;

    while ((*p) != NULL) {
        print_fn((*p)->data);
        p = &(*p)->next;
    }    
}

static const List _singleList = {
    sizeof(_SingleList),
    singleListCtor,
    singleListDtor,
    singleListInsert,
    singleListRemove,
    singleListIterator,
    singleListGetItem,
    singleListGetSize,
    singleListPrint,
};

const void *SingleList = &_singleList;
