#include "abstractOperator.h"
#include "zipFile.h"
#include <stdio.h>

static void zipFileOperation(const void *_self) {
    fprintf(stdout, "压缩\n");
}

static const AbstractOperator _zipFile = {
    sizeof(_ZipFile),
    NULL,
    NULL,
    zipFileOperation
};

const void *ZipFile = &_zipFile;
