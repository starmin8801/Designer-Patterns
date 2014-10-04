#include "status.h"
#include "sunStatus.h"
#include <stdio.h>

static void sunStatusVisitSeedA(const void *_self, void *_elm) {
    (void)_self;
    (void)_elm;

    fprintf(stdout, "Sun will visit Seed A...\n");
}

static void sunStatusVisitSeedB(const void *_self, void *_elm) {
    (void)_self;
    (void)_elm;

    fprintf(stdout, "Sun will visit Seed B...\n");
}

static const Status _sunStatus = {
    sizeof(_SunStatus),
    NULL,
    NULL,
    sunStatusVisitSeedA,
    sunStatusVisitSeedB
};

const void *SunStatus = &_sunStatus;
