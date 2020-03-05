#include <iostream>
#include "NegativeExpression.hpp"
using namespace std;

NegativeExpression::NegativeExpression(Expression* a): UnaryExpression(a) {}
int NegativeExpression::solve() {
    return x->solve() * -1;
}