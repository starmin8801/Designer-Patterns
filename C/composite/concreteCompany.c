#include "company.h"
#include "concreteCompany.h"
#include "new.h"
#include "singleList.h"
#include <stdio.h>
#include <assert.h>

static void *concreteCompanyCtor(void *_self, va_list *params) {
    _ConcreteCompany *self = _self;

    self->name = va_arg(*params, char*);
    self->listCompany = New(SingleList);

    return self;
}

static void* concreteCompanyDtor(void *_self) {
    _ConcreteCompany *self = _self;

    self->name = NULL;
    Delete(self->listCompany);
    self->listCompany = NULL;

    return self;
}

static void concreteCompanyAdd(void *_self, void *_company) {
    _ConcreteCompany *self = _self;
    
    Insert(self->listCompany, _company);
}

static void display(const void *_comp, va_list *params) {
    const Company * const *comp = _comp;

    int depth = va_arg(*params, int);
    assert(_comp && *comp && (*comp)->display);
    (*comp)->display(_comp, depth);
}

static void concreteCompanyDisplay(const void *_self, int depth) {
    const _ConcreteCompany *self = _self;
    
    int i = 0;
    for (; i < depth; ++i) {
        fprintf(stdout, "-");
    }

    fprintf(stdout, "%s\n", self->name);

    Iterator((const void*)self->listCompany, display, depth + 2);
}

static const Company _concreteCompany = {
    sizeof(_ConcreteCompany),
    concreteCompanyCtor,
    concreteCompanyDtor,
    concreteCompanyAdd,
    concreteCompanyDisplay
};

const void *ConcreteCompany = &_concreteCompany;
