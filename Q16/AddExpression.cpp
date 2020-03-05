#include <iostream>
#include "AddExpression.hpp"
using namespace std;

AddExpression::AddExpression(Expression* a, Expression* b): BinaryExpression(a,b) {}
int AddExpression::solve() {
    return x->solve() + y->solve();
}