#include "os.h"
#include "computer.h"
#include "ibmComputer.h"
#include <stdarg.h>
#include <assert.h>

static void *ibmComputerCtor(void *_self, va_list *params) {
    _IBMComputer *self = _self;

    return self;
}

static void *ibmComputerDtor(void *_self) {
    _IBMComputer *self = _self;

    return self;
}

static void ibmComputerInstallOS(const void *_self, const void *_os) {
    const OS * const *os = _os;

    assert(_os && *os && (*os)->run);

    (*os)->run(_os);
}

static const Computer _ibmComputer = {
    sizeof(_IBMComputer),
    ibmComputerCtor,
    ibmComputerDtor,
    ibmComputerInstallOS
};

const void *IBMComputer = &_ibmComputer;
