#ifndef _TRIPLET_HPP_
#define _TRIPLET_HPP_

#include <iostream>

template <class A, class B, class C>
class Triplet {
private:
    A first;
    B second;
    C third;
public:
    Triplet() {}
    Triplet(A first, B second, C third) {
        this->first = first;
        this->second = second;
        this->third = third;
    }
    Triplet(const Triplet& tr) {
        this->first = first;
        this->second = second;
        this->third = third;
    }

    A getFirst() {
        return this->first;
    }
    B getSecond() {
        return this->second;
    }
    C getThird() {
        return this->third;
    }

    void setFirst(A first) {
        this->first = first;
    }
    void setSecond(B second) {
        this->second = second;
    }
    void setThird(C third) {
        this->third = third;
    }

    bool operator==(const Triplet& t) {
        return (this->first == t.first) && (this->second == t.second) && (this->third == t.third);
    }

    bool operator!=(const Triplet& t) {
        return (this->first != t.first) || (this->second != t.second) || (this->third != t.third);
    }
};

#endif