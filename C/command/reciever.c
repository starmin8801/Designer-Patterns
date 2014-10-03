#include "abstractReciever.h"
#include "reciever.h"
#include <stdio.h>

static void recieverAction(const void *_self) {
    (void)_self;

    fprintf(stdout, "Do action!\n");
}

static const AbstractReciever _reciever = {
    sizeof(_Reciever),
    NULL,
    NULL,
    recieverAction
};

const void *Reciever = &_reciever;
