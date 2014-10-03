#include "reciever.h"
#include "readCommand.h"
#include "writeCommand.h"
#include "invoker.h"
#include "new.h"

int main(int argc, char *argv[]) {
    void *rev = New(Reciever);
    
    void *cmd1 = New(ReadCommand, rev);
    void *cmd2 = New(WriteCommand, rev);

    void *inv = New(Invoker);

    AddCmd(inv, cmd1);
    AddCmd(inv, cmd2);
    Notify(inv);

    DelCmd(inv, cmd1);
    Notify(inv);
    
    return 0;
}
