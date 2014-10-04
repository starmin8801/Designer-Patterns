#include "objectStructure.h"
#include "seedA.h"
#include "seedB.h"
#include "rainStatus.h"
#include "sunStatus.h"
#include "new.h"

int main(int argc, char *argv[]) {
    void *obj = New(ObjectStructure);

    Attach(obj, New(SeedA));
    Attach(obj, New(SeedB));

    Display(obj, New(RainStatus));
    Display(obj, New(SunStatus));
    
    return 0;
}
