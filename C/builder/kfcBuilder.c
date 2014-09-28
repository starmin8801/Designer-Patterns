#include "builder.h"
#include "kfcBuilder.h"
#include <stdarg.h>
#include <stdio.h>

static void* kfcBuilderCtor(void *_self, va_list *params) {
    _KFCBuilder *self = _self;

    return self;
}

static void* kfcBuilderDtor(void *_self) {
    _KFCBuilder *self = _self;

    return self;
}

static void kfcBuilderBuilderStep1(const void *_self) {
    (void)_self;
    fprintf(stdout, "KFC Step1: \n");
}

static void kfcBuilderBuilderStep2(const void *_self) {
    (void)_self;
    fprintf(stdout, "KFC Step2: \n");
}

static void kfcBuilderBuilderStep3(const void *_self) {
    (void)_self;
    fprintf(stdout, "KFC Step3: \n");
}

static void kfcBuilderBuilderStep4(const void *_self) {
    (void)_self;
    fprintf(stdout, "KFC Step4: \n");
}

static const Builder _kfcBuilder = {
    sizeof(_KFCBuilder),
    kfcBuilderCtor,
    kfcBuilderDtor,
    kfcBuilderBuilderStep1,
    kfcBuilderBuilderStep2,
    kfcBuilderBuilderStep3,
    kfcBuilderBuilderStep4
};

const void *KFCBuilder = &_kfcBuilder;
