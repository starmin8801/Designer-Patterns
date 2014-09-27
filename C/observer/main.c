#include "new.h"
#include "datasubject.h"
#include "sheetobserver.h"
#include "chatobserver.h"

int main(int argc, char *argv[]) {
    void *sub = New(DataSubject);

    void *o1 = New(SheetObserver, sub);
    void *o2 = New(ChatObserver, sub);

    SetState(sub, "old data");
    Notify(sub);

    SetState(sub, "new data");
    Notify(sub);

    Update(o1, sub);
    
    return 0;
}
