#ifndef __NEGATIVEEXPRESSION_HPP
#define __NEGATIVEEXPRESSION_HPP
#include "Expression.hpp"

class NegativeExpression: public UnaryExpression {
public:
    NegativeExpression(Expression* a);
    int solve();
};

#endif