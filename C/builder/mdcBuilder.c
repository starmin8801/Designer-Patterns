#include "builder.h"
#include "mdcBuilder.h"
#include <stdarg.h>
#include <stdio.h>

static void* mdcBuilderCtor(void *_self, va_list *params) {
    _MDCBuilder *self = _self;

    return self;
}

static void* mdcBuilderDtor(void *_self) {
    _MDCBuilder *self = _self;

    return self;
}

static void mdcBuilderBuilderStep1(const void *_self) {
    (void)_self;
    fprintf(stdout, "MDC Step1: \n");
}

static void mdcBuilderBuilderStep2(const void *_self) {
    (void)_self;
    fprintf(stdout, "MDC Step2: \n");
}

static void mdcBuilderBuilderStep3(const void *_self) {
    (void)_self;
    fprintf(stdout, "MDC Step3: \n");
}

static void mdcBuilderBuilderStep4(const void *_self) {
    (void)_self;
    fprintf(stdout, "MDC Step4: \n");
}

static const Builder _mdcBuilder = {
    sizeof(_MDCBuilder),
    mdcBuilderCtor,
    mdcBuilderDtor,
    mdcBuilderBuilderStep1,
    mdcBuilderBuilderStep2,
    mdcBuilderBuilderStep3,
    mdcBuilderBuilderStep4
};

const void *MDCBuilder = &_mdcBuilder;
