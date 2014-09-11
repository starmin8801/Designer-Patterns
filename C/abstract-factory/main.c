#include "new.h"
#include "factoryA.h"
#include "factoryB.h"

int main(int argc, char *argv[]) {
    void *facA = New(FactoryA);
    void *facB = New(FactoryB);

    void *pro1 = CreateProduct(facA);
    void *pro2 = CreateProduct(facB);
    void *pro3 = CreateProduct(facA);

    Show(pro1);
    Show(pro2);
    Show(pro3);

    void *pro4 = CreateChip(facA);
    void *pro5 = CreateChip(facB);
    void *pro6 = CreateChip(facA);

    Show(pro4);
    Show(pro5);
    Show(pro6);
    
    Delete(facA);
    Delete(facB);
    Delete(pro1);
    Delete(pro2);
    Delete(pro3);
    Delete(pro4);
    Delete(pro5);
    Delete(pro6);

    
    return 0;
}
