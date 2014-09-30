#include "state.h"
#include "compressState.h"
#include "abstractWork.h"
#include "actState.h"
#include "new.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static void compressStateOperation(const void *_self, void *_work) {
    (void)_self;

    AbstractWork **work = _work;

    assert(_work && *work && (*work)->getStep && (*work)->setState);

    if ((*work)->getStep(_work) == 2) {
        fprintf(stdout, "Step: %d 压缩操作\n", (*work)->getStep(_work));
    } else {
        (*work)->setState(_work, New(ActState));
        (*work)->operation(_work);
    }
}

static const State _compressState = {
    sizeof(_CompressState),
    NULL,
    NULL,
    compressStateOperation
};

const void *CompressState = &_compressState;
