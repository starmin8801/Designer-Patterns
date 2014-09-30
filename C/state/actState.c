#include "state.h"
#include "actState.h"
#include "exhaustState.h"
#include "abstractWork.h"
#include "new.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static void actStateOperation(const void *_self, void *_work) {
    (void)_self;

    AbstractWork **work = _work;

    assert(_work && *work && (*work)->getStep && (*work)->setState);
    
    if ((*work)->getStep(_work) == 3) {
        fprintf(stdout, "Step: %d 做功操作\n", (*work)->getStep(_work));
    } else {
        (*work)->setState(_work, New(ExhaustState));
        (*work)->operation(_work);
    }
}

static const State _actState = {
    sizeof(_ActState),
    NULL,
    NULL,
    actStateOperation
};

const void *ActState = &_actState;
