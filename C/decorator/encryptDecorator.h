#ifndef ENCRYPTDECORATOR_H
#define ENCRYPTDECORATOR_H

typedef struct {
    const void *_;
    void (*addedEncryptBehavior)(const void *_self);
} _EncryptDecorator;

extern const void *EncryptDecorator;

#endif
