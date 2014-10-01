#include "un.h"
#include "japan.h"
#include "china.h"
#include "new.h"

int main(int argc, char *argv[]) {
    void *mediator = New(UN);
    void *pJapan = New(Japan);
    void *pChina = New(China);

    SetJanpa(mediator, pJapan);
    SetChina(mediator, pChina);

    SetMediator(pJapan, mediator);
    SetMediator(pChina, mediator);
    
    SendMessage(pJapan, "钓鱼岛是我们的，哈哈哈...\n");
    SendMessage(pChina, "操，你他妈再乱放屁，小心我弄死你!\n");

    Delete(pJapan);
    Delete(pChina);
    Delete(mediator);
    
    return 0;
}
