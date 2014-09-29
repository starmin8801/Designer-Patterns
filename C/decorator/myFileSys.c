#include "fileSys.h"
#include "myFileSys.h"
#include <stdio.h>

static void *myFileSysCtor(void *_self, va_list *params) {
    _MyFileSys *self = _self;

    return self;
}

static void *myFileSysDtor(void *_self) {
    _MyFileSys *self = _self;

    return self;
}

static void myFileSysOperation(const void *_self) {
    (void)_self;

    fprintf(stdout, "MyFileSys operation...\n");
}

static const FileSys _myFileSys = {
    sizeof(_MyFileSys),
    myFileSysCtor,
    myFileSysDtor,
    myFileSysOperation
};

const void *MyFileSys = &_myFileSys;
