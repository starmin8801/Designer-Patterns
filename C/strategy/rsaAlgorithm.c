#include "algorithm.h"
#include "rsaAlgorithm.h"
#include <stdio.h>

static void rsaAlgorithmCalculate(const void *_self) {
    (void)_self;

    fprintf(stdout, "RSA algorithm ...\n");
}

static const Algorithm _rsaAlgorithmCalculate = {
    sizeof(_RSA_Algorithm),
    NULL,
    NULL,
    rsaAlgorithmCalculate
};

const void *RSA_Algorithm = &_rsaAlgorithmCalculate;
