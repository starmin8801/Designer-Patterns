#include "state.h"
#include "exhaustState.h"
#include "abstractWork.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

static void exhaustStateOperation(const void *_self, void *_work) {
    (void)_self;

    AbstractWork **work = _work;

    assert(_work && *work && (*work)->getStep);

    if ((*work)->getStep(_work) == 4) {
        fprintf(stdout, "Step: %d 排气操作\n", (*work)->getStep(_work));
    }
}

static const State _extrinsicState = {
    sizeof(_ExhaustState),
    NULL,
    NULL,
    exhaustStateOperation
};

const void *ExhaustState = &_extrinsicState;
