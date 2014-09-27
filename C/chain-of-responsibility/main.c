#include "new.h"
#include "concreteHandleA.h"
#include "concreteHandleB.h"
#include "concreteHandleC.h"

int main(int argc, char *argv[]) {
    void *h1 = New(ConcreteHandleA);
    void *h2 = New(ConcreteHandleB);
    void *h3 = New(ConcreteHandleC);

    SetSuccessor(h1, h2);
    SetSuccessor(h2, h3);

    HandleRequest(h1, 300);
    HandleRequest(h1, 600);
    HandleRequest(h1, 1500);
    HandleRequest(h1, 3000);
    
    Delete(h1);
    Delete(h2);
    Delete(h3);
    
    return 0;
}
