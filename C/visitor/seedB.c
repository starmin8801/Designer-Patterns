#include "seed.h"
#include "seedB.h"
#include "status.h"
#include <assert.h>

static void seedBAccept(void *_self, void *_vis) {
    Status **vis = _vis;

    assert(_vis && *vis && (*vis)->visitSeedA);

    (*vis)->visitSeedA(_vis, _self);
}

static const Seed _seedB = {
    sizeof(_SeedB),
    NULL,
    NULL,
    seedBAccept
};

const void *SeedB = &_seedB;
