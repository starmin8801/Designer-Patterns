#ifndef ZIPFILE_H
#define ZIPFILE_H

typedef struct {
    const void *_;
    void (*operation2)(const void *_self);
} _ZipFile;

extern const void *ZipFile;

#endif
