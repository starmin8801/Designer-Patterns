#include "os.h"
#include "computer.h"
#include "hpComputer.h"
#include <stdarg.h>
#include <assert.h>

static void *hpComputerCtor(void *_self, va_list *params) {
    _HPComputer *self = _self;

    return self;
}

static void *hpComputerDtor(void *_self) {
    _HPComputer *self = _self;

    return self;
}

static void hpComputerInstallOS(const void *_self, const void *_os) {
    const OS * const *os = _os;

    assert(_os && *os && (*os)->run);

    (*os)->run(_os);
}

static const Computer _hpComputer = {
    sizeof(_HPComputer),
    hpComputerCtor,
    hpComputerDtor,
    hpComputerInstallOS
};

const void *HPComputer = &_hpComputer;
