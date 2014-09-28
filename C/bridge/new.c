#include "new.h"
#include "abstractClass.h"
#include "computer.h"
#include "os.h"
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>

void *New(const void *_class, ...) {
    const AbstractClass *class = _class;

    void *p = calloc(1, class->size);

    assert(p);
    *(const AbstractClass **)p = class;
    
    if (class->ctor) {
        va_list params;

        va_start(params, _class);
        p = class->ctor(p, &params);
        va_end(params);
    }

    return p;
}

void Delete(void *_class) {
    const AbstractClass **class = _class;

    if (_class && *class && (*class)->dtor) {
        _class = (*class)->dtor(_class);
    }

    free(_class);
}

void InstallOS(const void *_computer, const void *_os) {
    const Computer * const *computer = _computer;

    assert(_computer && _os && *computer && (*computer)->installOS);

    (*computer)->installOS(_computer, _os);
}
