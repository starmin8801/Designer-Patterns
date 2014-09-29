#ifndef ZIPDECORATOR_H
#define ZIPDECORATOR_H

typedef struct {
    const void *_;
    void (*addedZipBehavior)(const void *_self);
} _ZipDecorator;

extern const void *ZipDecorator;

#endif
