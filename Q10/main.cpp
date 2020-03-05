#include <iostream>
#include "Vehicle.h"
#include "Bike.h"
#include "Car.h"
using namespace std;

int main() {
    Vehicle a(3,2);
    Vehicle b(a);
    Vehicle c(6,50);
    Car d(8);
    Car e(d);
    Car f(6);
    Bike g;

    f.drive();
    g.show();
    g.ride();

    return 0;
}