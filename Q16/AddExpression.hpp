#ifndef __ADDEXPRESSION_HPP
#define __ADDEXPRESSION_HPP
#include "Expression.hpp"

class AddExpression: public BinaryExpression {
public:
    AddExpression(Expression* a, Expression* b);
    int solve();
};

#endif