#include "new.h"
#include "concreteClass1.h"
#include "concreteClass2.h"

int main(int argc, char *argv[]) {
    void *p1 = New(ConcreteClass1, "ConcreteClass1", 10);
    void *p2 = New(ConcreteClass2, "ConcreteClass2", 20.1);

    TemplateMethod(p1);
    TemplateMethod(p2); 

    Delete(p1);
    Delete(p2);
    
    return 0;
}
