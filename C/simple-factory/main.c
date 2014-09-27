#include "new.h"
#include "factory.h"

int main(int argc, char *argv[]) {
    void *fac = New(Factory);

    void *pro1 = CreateProduct(fac, PRODUCT_A);
    void *pro2 = CreateProduct(fac, PRODUCT_B);

    Show(pro1);
    Show(pro2);

    Delete(fac);
    Delete(pro1);
    Delete(pro2);
    
    return 0;
}
