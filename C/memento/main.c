#include "new.h"
#include "originator.h"

int main(int argc, char *argv[]) {
    void *o = New(Originator);

    SetState(o, "old");
    PrintState(o);

    void *m = CreateMemento(o);

    SetState(o, "new");
    PrintState(o);

    RestoreToMemento(o, m);
    PrintState(o);
    
    return 0;
}
