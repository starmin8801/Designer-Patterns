#include "new.h"
#include "concretePrototype.h"
#include <assert.h>

int main(int argc, char *argv[]) {
    void *p1 = New(ConcretePrototype);
    void *p2 = p1;

    int item = 3;
    void *p3 = New(ConcretePrototype, &item);
    void *p4 = Clone(p3);

    assert(((_ConcretePrototype*)p4)->item == ((_ConcretePrototype*)p3)->item);
    
    return 0;
}
