// main.cpp
#include "A.hpp"
#include "B.hpp"

void set(A& a) {
    a.setValue(888);
}

int main() {
  B b; /** ANDA HARUS MENGGUNAKAN DEFAULT CONSTRUCTOR */
  
  // Your code goes here :)
  set(b);
  b.setValue(10888);
  
  b.print(); // OUTPUT: (888, 10888)
  return 0;
}