#ifndef __C_HPP
#define __C_HPP

#include "A.hpp"
#include "B.hpp"

class C: public B, public A {
public:
    C();
    void sing();
};

#endif