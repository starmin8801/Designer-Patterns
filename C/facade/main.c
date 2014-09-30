#include "new.h"
#include "operatorWapper.h"

int main(int argc, char *argv[]) {
    void *op = New(OperatorWapper);

    MethodA(op);
    MethodB(op);
    
    return 0;
}
