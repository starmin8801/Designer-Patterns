#include "chip.h"
#include "chipA.h"
#include <stdarg.h>
#include <stdio.h>

static void *chipACtor(void *_self, va_list *params) {
    _ChipA *self = _self;

    return self;
}

static void *chipADtor(void *_self) {
    _ChipA *self = _self;

    return self;
}

static void chipAShow(const void *_self) {
    (void)_self;
    fprintf(stdout, "Chip A\n");
}

static const Chip _chip = {
    sizeof(_ChipA),
    chipACtor,
    chipADtor,
    chipAShow
};

const void *ChipA = &_chip;
