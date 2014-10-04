#include "status.h"
#include "rainStatus.h"
#include <stdio.h>

static void rainStatusVisitSeedA(const void *_self, void *_elm) {
    (void)_self;
    (void)_elm;

    fprintf(stdout, "Rain will visit Seed A...\n");
}

static void rainStatusVisitSeedB(const void *_self, void *_elm) {
    (void)_self;
    (void)_elm;

    fprintf(stdout, "Rain will visit Seed B...\n");
}

static const Status _rainStatus = {
    sizeof(_RainStatus),
    NULL,
    NULL,
    rainStatusVisitSeedA,
    rainStatusVisitSeedB
};

const void *RainStatus = &_rainStatus;
