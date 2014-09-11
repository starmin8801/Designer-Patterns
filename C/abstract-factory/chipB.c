#include "chip.h"
#include "chipB.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static void *chipBCtor(void *_self, va_list *params) {
    _ChipB *self = _self;

    return self;
}

static void *chipBDtor(void *_self) {
    _ChipB *self = _self;

    return self;
}

static void chipBShow(const void *_self) {
    (void)_self;
    fprintf(stdout, "Chip B\n");
}

static const Chip _chip = {
    sizeof(_ChipB),
    chipBCtor,
    chipBDtor,    
    chipBShow
};

const void *ChipB = &_chip;
