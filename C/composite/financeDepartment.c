#include "company.h"
#include "financeDepartment.h"
#include "new.h"
#include <stdio.h>
#include <assert.h>

static void *financeDepartmentCtor(void *_self, va_list *params) {
    _FinanceDepartment *self = _self;

    self->name = va_arg(*params, char*);

    return self;
}

static void* financeDepartmentDtor(void *_self) {
    _FinanceDepartment *self = _self;

    self->name = NULL;

    return self;
}

static void display(const void *_comp, va_list *params) {
    const Company * const *comp = _comp;

    int depth = va_arg(*params, int);
    assert(_comp && *comp && (*comp)->display);
    (*comp)->display(_comp, depth);
}

static void financeDepartmentDisplay(const void *_self, int depth) {
    const _FinanceDepartment *self = _self;
    
    int i = 0;
    for (; i < depth; ++i) {
        fprintf(stdout, "-");
    }

    fprintf(stdout, "%s\n", self->name);
}

static const Company _financeDepartment = {
    sizeof(_FinanceDepartment),
    financeDepartmentCtor,
    financeDepartmentDtor,
    NULL,
    financeDepartmentDisplay
};

const void *FinanceDepartment = &_financeDepartment;
