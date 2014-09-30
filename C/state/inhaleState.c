#include "inhaleState.h"
#include "state.h"
#include "abstractWork.h"
#include "compressState.h"
#include "new.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

static void inhaleStateOperation(const void *_self, void *_work) {
    (void)_self;

    AbstractWork **work = _work;

    assert(_work && *work && (*work)->getStep && (*work)->setState);

    if ((*work)->getStep(_work) == 1) {
        fprintf(stdout, "Step: %d 吸气操作\n", (*work)->getStep(_work));
    } else {
        (*work)->setState(_work, New(CompressState));
        (*work)->operation(_work);
    }    
}

static const State _inhaleState = {
    sizeof(_InhaleState),
    NULL,
    NULL,
    inhaleStateOperation
};

const void *InhaleState = &_inhaleState;
