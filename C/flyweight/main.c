#include "new.h"
#include "flyweightFactory.h"
#include "unsharedConcreteFlyweight.h"

int main(int argc, char *argv[]) {
    void *fc = New(FlyweightFactory);

    void *fw1 = GetFlyweight(fc, "Object A");
    void *fw2 = GetFlyweight(fc, "Object B");
    
    void *fw3 = GetFlyweight(fc, "Object A");

    char *extrinsicState = "Hello world!";

    Operation(fw1, extrinsicState);
    Operation(fw2, extrinsicState);
    Operation(fw3, extrinsicState);
    
    void *unsharefw1 = New(UnsharedConcreteFlyweight);

    Operation(unsharefw1, extrinsicState);
        
    return 0;
}
