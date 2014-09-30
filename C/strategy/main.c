#include "new.h"
#include "rsaAlgorithm.h"

int main(int argc, char *argv[]) {
    void *algorithmContext = New(RSA_Algorithm);

    Calculate(algorithmContext);
    
    return 0;
}
