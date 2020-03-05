#include <iostream>
#include "Ball.hpp"
using namespace std;

Ball::Ball() {
    radius = 1;
}              // Membuat Ball dengan nilai radius 1
Ball::Ball(int radius) {
    this->radius = radius;
}    // Membuat Ball dengan nilai radius r
Ball::Ball(const Ball& b) {
    radius = b.radius;
}
Ball::~Ball() {}
void Ball::bounce() {
    cout << "bo";
    for(int i = 0; i < radius; i++) {
        cout << "i";
    }
    cout << "ng" << endl;
}    