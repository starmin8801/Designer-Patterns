#include "new.h"
#include "flyweightFactory.h"

int main(int argc, char *argv[]) {
    void *fc = New(FlyweightFactory);

    void *fw1 = GetFlyweight(fc, "Object A");
    void *fw2 = GetFlyweight(fc, "Object B");
    
    void *fw3 = GetFlyweight(fc, "Object A");

    return 0;
}
