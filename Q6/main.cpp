#include <iostream>
#include "Box.hpp"
using namespace std;

int main() {
    Box b1(2);
    Box* b2 = new Box();
    Box b3(1);
    *b2 = b1;
    Box b4(b3);
    b2->peek();
    b4.peek();
    delete b2;

    return 0;
}