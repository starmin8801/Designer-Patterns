#include "new.h"
#include "myFileSys.h"
#include "zipDecorator.h"
#include "killVirDecorator.h"
#include "encryptDecorator.h"

int main(int argc, char *argv[]) {
    void *fileSys = New(MyFileSys);
    void *dec1 = New(ZipDecorator, fileSys);
    void *dec2 = New(KillVirDecorator, dec1);
    void *dec3 = New(EncryptDecorator, dec2);

    Operation(dec3);

    return 0;
}
