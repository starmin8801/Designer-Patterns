#include "new.h"
#include "inhaleState.h"
#include "work.h"

int main(int argc, char *argv[]) {
    void *st = New(InhaleState);
    void *work = New(Work, st);

    int i = 1;
    for (; i < 5; ++i) {
        SetStep(work, i);
        Operation(work);
    }

    Delete(work);
    
    return 0;
}
