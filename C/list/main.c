#include "singleList.h"
#include "new.h"
#include <stdio.h>
#include <string.h>

void print_int(void *data) {
    fprintf(stdout, "The data is %d\n", *(int *)data);
}

void mult_int(void *data, va_list *params) {
    int step = va_arg(*params, int);
    *(int *)data *= step;
}

int main(int argc, char *argv[]) {
    void *list = New(SingleList);
    int a = 3;
    int b = 4;
    int c = 5;
    
    Insert(list, &a);
    Insert(list, &b);
    Insert(list, &c);

    Print(list, print_int);
    
    Remove(list, &b);
    
    Print(list, print_int);

    Iterator(list, mult_int, c);

    Print(list, print_int);
    
    Delete(list);
    
    return 0;
}
