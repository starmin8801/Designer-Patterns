#include "os.h"
#include "linuxOS.h"
#include <stdarg.h>
#include <stdio.h>

static void *linuxOSCtor(void *_self, va_list *params) {
    _LinuxOS *self = _self;

    return self;
}

static void *linuxOSDtor(void *_self) {
    _LinuxOS *self = _self;

    return self;
}

static void linuxOSRun(const void *_self) {
    (void)_self;

    fprintf(stdout, "Run Linuxs\n");
}

static const OS _linuxOS = {
    sizeof(_LinuxOS),
    linuxOSCtor,
    linuxOSDtor,
    linuxOSRun
};

const void *LinuxOS = &_linuxOS;
