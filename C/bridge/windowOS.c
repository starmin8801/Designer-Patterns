#include "os.h"
#include "windowOS.h"
#include <stdarg.h>
#include <stdio.h>

static void *windowOSCtor(void *_self, va_list *params) {
    _WindowOS *self = _self;

    return self;
}

static void *windowOSDtor(void *_self) {
    _WindowOS *self = _self;

    return self;
}

static void windowOSRun(const void *_self) {
    (void)_self;

    fprintf(stdout, "Run Windows\n");
}

static const OS _windowOS = {
    sizeof(_WindowOS),
    windowOSCtor,
    windowOSDtor,
    windowOSRun
};

const void *WindowOS = &_windowOS;
