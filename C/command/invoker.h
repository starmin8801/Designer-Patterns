#ifndef INVOKER_H
#define INVOKER_H

typedef struct {
    const void *_self;
    void *cmd;
    void *cmdList;
} _Invoker;

extern const void *Invoker;

#endif
