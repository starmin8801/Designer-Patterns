#include "new.h"
#include "windowOS.h"
#include "linuxOS.h"
#include "ibmComputer.h"
#include "hpComputer.h"

int main(int argc, char *argv[]) {
    void *os1 = New(WindowOS);
    void *os2 = New(LinuxOS);

    void *computer1 = New(IBMComputer);

    InstallOS(computer1, os1);
    InstallOS(computer1, os2);

    return 0;
}
