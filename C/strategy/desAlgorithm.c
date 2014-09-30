#include "algorithm.h"
#include "desAlgorithm.h"
#include <stdio.h>

static void desAlgorithmCalculate(const void *_self) {
    (void)_self;

    fprintf(stdout, "DES algorithm ...\n");
}

static const Algorithm _desAlgorithmCalculate = {
    sizeof(_DES_Algorithm),
    NULL,
    NULL,
    desAlgorithmCalculate
};

const void *DES_Algorithm = &_desAlgorithmCalculate;
