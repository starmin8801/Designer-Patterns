#include "list.h"
#include "new.h"
#include <stdlib.h>

static void *singleListCtor(void *_self, va_list *params) {
    _SingleList *self = _self;

    self->head = (Node*)calloc(1, sizeof(Node));

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
    
    return self;    
}

static void singleListInsert(void *_self, void *data) {
    _SingleList *self = _self;
    Node *node = (Node*)calloc(1, sizeof(Node));

    Node **p = &self->head;
    for (; (*p) != NULL; p = &(*p)->next) {
        ;
    }

    node->data = data;
    node->next = *p;
    *p = node;
}

static void singleListRemove(void *_self, void *data) {
    _SingleList *self = _self;
    Node **p = &self->head;

    while ((*p) != NULL) {
        Node *node = *p;
        if (node->data == data) {
            *p = node->next;
        } else {
            p = &(*p)->next;
        }
    }
}

static void singleListPrint(void *_self, Print_FN print_fn) {
    _SingleList *self = _self;
    Node **p = &self->head->next;

    while ((*p) != NULL) {
        print_fn((*p)->data);
        p = &(*p)->next;
    }    
}

static _SingleList _singleList = {
    sizeof(_SingleList),
    singleListCtor,
    singleListDtor,
    singleListInsert,
    singleListRemove,
    singleListPrint,
    NULL
};

const void *SingleList = &_singleList;
