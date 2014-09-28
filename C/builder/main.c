#include "new.h"
#include "director.h"
#include "kfcBuilder.h"

int main(int argc, char *argv[]) {
    void *kfc = New(KFCBuilder);
    void *director = New(Director, kfc);
    
    Create(director);
    
    return 0;
}
