#include "abstractOperator.h"
#include "killVirus.h"
#include <stdio.h>

static void killVirusOperation(const void *_self) {
    fprintf(stdout, "杀毒\n");
}

static const AbstractOperator _killVirus = {
    sizeof(_KillVirus),
    NULL,
    NULL,
    killVirusOperation
};

const void *KillVirus = &_killVirus;
