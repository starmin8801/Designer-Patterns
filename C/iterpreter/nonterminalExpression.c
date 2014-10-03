#include "abstractExpression.h"
#include "nonterminalExpression.h"
#include "abstractContext.h"
#include <stdio.h>
#include <assert.h>

static void *nonterminalExpressionCtor(void *_self, va_list *params) {
    _NONTerminalExpression *self = _self;

    self->statement = va_arg(*params, char*);

    return self;
}

static void *nonterminalExpressionDtor(void *_self) {
    _NONTerminalExpression *self = _self;

    self->statement = NULL;

    return self;
}

static void nonterminalExpressionInterpret(const void *_self, void *_context) {
    const _NONTerminalExpression *self = _self;
    AbstractContext **context = _context;

    assert(_context && *context && (*context)->getData);
    fprintf(stderr, "Nonterminal Expression... %s:%s\n", self->statement, (*context)->getData(_context));
}

static const AbstractExpresion _nonterminalExpression = {
    sizeof(_NONTerminalExpression),
    nonterminalExpressionCtor,
    nonterminalExpressionDtor,
    nonterminalExpressionInterpret
};

const void *NONTerminalExpression = &_nonterminalExpression;
