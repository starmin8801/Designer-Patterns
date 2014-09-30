#include "abstractOperator.h"
#include "encryptFile.h"
#include <stdio.h>

static void encryptFileOperation(const void *_self) {
    fprintf(stdout, "加密\n");
}

static const AbstractOperator _encryptFile = {
    sizeof(_EncryptFile),
    NULL,
    NULL,
    encryptFileOperation
};

const void *EncryptFile = &_encryptFile;
