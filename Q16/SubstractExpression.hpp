#ifndef __SubstractExpression_HPP
#define __SubstractExpression_HPP

#include "Expression.hpp"

class SubstractExpression: public BinaryExpression {
public:
    SubstractExpression(Expression* a, Expression* b);
    int solve();
};

#endif