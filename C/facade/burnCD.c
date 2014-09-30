#include "abstractOperator.h"
#include "burnCD.h"
#include <stdio.h>

static void burnCDOperation(const void *_self) {
    fprintf(stdout, "刻录\n");
}

static const AbstractOperator _burnCD = {
    sizeof(_BurnCD),
    NULL,
    NULL,
    burnCDOperation
};

const void *BurnCD = &_burnCD;
