#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
using namespace std;

int main() {
    Car* a = new Car(4);
    Vehicle* b = new Car(10);
    Vehicle* c = new Bike();
    Vehicle* d = new Vehicle(*c);
    
    delete c;
    b->drive();
    d->clean();
    a->drive();
    d->park();
    delete b;
    delete d;
    delete a;

    return 0;
}