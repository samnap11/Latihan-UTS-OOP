#include <iostream>
#include "SubstractExpression.hpp"
using namespace std;

SubstractExpression::SubstractExpression(Expression* a, Expression* b): BinaryExpression(a,b) {}
int SubstractExpression::solve() {
    return x->solve() - y->solve();
}