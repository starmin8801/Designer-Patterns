#include "new.h"
#include "abstractClass.h"
#include "abstractDirector.h"
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

void Create(const void *_director) {
    const AbstractDirector * const *director = _director;

    if (_director && *director && (*director)->create) {
        (*director)->create(_director);
    }
}
