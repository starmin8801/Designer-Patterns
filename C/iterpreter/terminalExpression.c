#include "abstractExpression.h"
#include "terminalExpression.h"
#include "abstractContext.h"
#include <stdio.h>
#include <assert.h>

static void *terminalExpressionCtor(void *_self, va_list *params) {
    _TerminalExpression *self = _self;

    self->statement = va_arg(*params, char*);

    return self;
}

static void *terminalExpressionDtor(void *_self) {
    _TerminalExpression *self = _self;

    self->statement = NULL;

    return self;
}

static void terminalExpressionInterpret(const void *_self, void *_context) {
    const _TerminalExpression *self = _self;
    AbstractContext **context = _context;

    assert(_context && *context && (*context)->getData);
    fprintf(stderr, "Terminal Expression... %s:%s\n", self->statement, (*context)->getData(_context));
}

static const AbstractExpresion _terminalExpression = {
    sizeof(_TerminalExpression),
    terminalExpressionCtor,
    terminalExpressionDtor,
    terminalExpressionInterpret
};

const void *TerminalExpression = &_terminalExpression;
