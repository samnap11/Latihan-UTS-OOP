#include <iostream>
#include "C.hpp"
using namespace std;

C::C(): B(), A() {}

void C::sing() {
    B::sing();
    A::sing();
}