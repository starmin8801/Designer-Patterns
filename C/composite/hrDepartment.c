#include "company.h"
#include "hrDepartment.h"
#include "new.h"
#include <stdio.h>
#include <assert.h>

static void *hrDepartmentCtor(void *_self, va_list *params) {
    _HRDepartment *self = _self;

    self->name = va_arg(*params, char*);

    return self;
}

static void* hrDepartmentDtor(void *_self) {
    _HRDepartment *self = _self;

    self->name = NULL;

    return self;
}

static void display(const void *_comp, va_list *params) {
    const Company * const *comp = _comp;

    int depth = va_arg(*params, int);
    assert(_comp && *comp && (*comp)->display);
    (*comp)->display(_comp, depth);
}

static void hrDepartmentDisplay(const void *_self, int depth) {
    const _HRDepartment *self = _self;
    
    int i = 0;
    for (; i < depth; ++i) {
        fprintf(stdout, "-");
    }

    fprintf(stdout, "%s\n", self->name);
}

static const Company _hrDepartment = {
    sizeof(_HRDepartment),
    hrDepartmentCtor,
    hrDepartmentDtor,
    NULL,
    hrDepartmentDisplay
};

const void *HRDepartment = &_hrDepartment;
