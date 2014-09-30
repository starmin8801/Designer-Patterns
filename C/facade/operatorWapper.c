#include "abstractWapper.h"
#include "operatorWapper.h"
#include "new.h"
#include "killVirus.h"
#include "zipFile.h"
#include "encryptFile.h"
#include "burnCD.h"
#include <stdlib.h>

static void operatorWapperMethodA(const void *_self) {
    (void)_self;

    void *kill = New(KillVirus);
    Operation(kill);

    void *zip = New(ZipFile);
    Operation(zip);

    void *encryptFile = New(EncryptFile);
    Operation(encryptFile);

    void *burnCD = New(BurnCD);
    Operation(burnCD);
}

static void operatorWapperMethodB(const void *_self) {
    (void)_self;
    
    void *kill = New(KillVirus);
    Operation(kill);

    void *burnCD = New(BurnCD);
    Operation(burnCD);
}

static const AbstractWapper _operatorWapper = {
    sizeof(_OperatorWapper),
    NULL,
    NULL,
    operatorWapperMethodA,
    operatorWapperMethodB
};

const void *OperatorWapper = &_operatorWapper;
