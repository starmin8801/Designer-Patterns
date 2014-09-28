#include "new.h"
#include "adaptee.h"
#include "target.h"
#include "adapter.h"

int main(int argc, char *argv[]) {
    void *ade = New(Adaptee);
    void *adt = New(Adapter);

    Request(adt);
    
    return 0;
}
