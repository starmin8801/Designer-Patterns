#include "new.h"
#include "factory.h"

int main(int argc, char *argv[]) {
    void *fac = NewFactory(Factory);

    void *pro1 = CreateProduct(fac, 0);
    void *pro2 = CreateProduct(fac, 1);
    void *pro3 = CreateProduct(fac, 2);
                                           

    Show(pro1);
    Show(pro2);
    Show(pro3);
    
    return 0;
}
