#ifndef SINGLELIST_H
#define SINGLELIST_H

typedef struct _Node {
    void *data;
    struct _Node *next;
} Node;

typedef struct {
    const void *_;
    Node *head;
    int size;
} _SingleList;

extern const void *SingleList;

#endif
