#include "new.h"
#include "context.h"
#include "terminalExpression.h"
#include "nonterminalExpression.h"
#include "abstractExpression.h"
#include "singleList.h"
#include <assert.h>
#include <stdarg.h>

static void interpret(void *_expression, va_list *params) {
    AbstractExpresion **expression = _expression;

    assert(_expression && *expression && (*expression)->interpret);
    
    (*expression)->interpret(_expression, va_arg(*params, void*));
}

int main(int argc, char *argv[]) {
    void *c = New(Context, "context");

    void *ls = New(SingleList);

    Insert(ls, New(TerminalExpression, "A"));
    Insert(ls, New(NONTerminalExpression, "B"));
    Insert(ls, New(TerminalExpression, "C"));
    Insert(ls, New(NONTerminalExpression, "D"));

    Iterator(ls, interpret, c);
    
    return 0;
}
