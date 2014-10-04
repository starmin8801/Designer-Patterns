#include "listContainer.h"
#include "new.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    void *container = New(ListContainer);
    void *iterator = CreateIterator(container);
    
    AddItemToContainer(container, "abc");
    AddItemToContainer(container, "def");
    AddItemToContainer(container, "ghi");
    AddItemToContainer(container, "jkl");

    
    fprintf(stdout, "%s\n", (char*)First(iterator));
    
    while (!isDone(iterator)) {
        char *item = Current(iterator);
        fprintf(stdout, "%s\n", item);
        Next(iterator);
    }

    RemoveItemFromContainer(container, "abc");

    fprintf(stdout, "%s\n", (char*)First(iterator));
    
    while (!isDone(iterator)) {
        char *item = Current(iterator);
        fprintf(stdout, "%s\n", item);
        Next(iterator);
    }    
    
    return 0;
}
