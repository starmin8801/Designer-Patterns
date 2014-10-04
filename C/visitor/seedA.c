#include "seed.h"
#include "seedA.h"
#include "status.h"
#include <assert.h>

static void seedAAccept(void *_self, void *_vis) {
    Status **vis = _vis;

    assert(_vis && *vis && (*vis)->visitSeedA);

    (*vis)->visitSeedA(_vis, _self);
}

static const Seed _seedA = {
    sizeof(_SeedA),
    NULL,
    NULL,
    seedAAccept
};

const void *SeedA = &_seedA;
