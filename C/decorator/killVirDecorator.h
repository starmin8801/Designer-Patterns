#ifndef KILLVIRDECORATOR_H
#define KILLVIRDECORATOR_H

typedef struct {
    const void *_;
    void (*addedKillVirBehavior)(const void *_self);
} _KillVirDecorator;

extern const void *KillVirDecorator;

#endif
