#include <iostream>
#include "RekeningGiro.h"
using namespace std;

// Konstruktor menginisialisi saldo (parameter 1) dan suku bunga (parameter 2)
// Set suku bunga 0.0 apabila suku bunga bernilai negatif
RekeningGiro::RekeningGiro(double sal, double interest): Rekening(sal) {
    sukuBunga = interest;
}

// Getter, Setter
void RekeningGiro::setSukuBunga(double interest) {
    sukuBunga = interest;
}
double RekeningGiro::getSukuBunga() const {
    return sukuBunga;
}

// Member Function
// Bunga dihitung dari saldo dikali suku bunga
double RekeningGiro::hitungBunga() {
    return getSaldo()*sukuBunga;
}