#include "algorithm.h"
#include "base64Algorithm.h"
#include <stdio.h>

static void base64AlgorithmCalculate(const void *_self) {
    (void)_self;

    fprintf(stdout, "BASE64 algorithm ...\n");
}

static const Algorithm _base64AlgorithmCalculate = {
    sizeof(_BASE64_Algorithm),
    NULL,
    NULL,
    base64AlgorithmCalculate
};

const void *BASE64_Algorithm = &_base64AlgorithmCalculate;
