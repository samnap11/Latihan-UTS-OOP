#include <iostream>
#include "Rekening.h"
using namespace std;

Rekening::Rekening(double a) {
    if(a < 0) {
        saldo = 0.00;
    }
    else{
        saldo = a;
    }
}

// Getter, Setter
void Rekening::setSaldo(double a) {
    saldo = a;
}
double Rekening::getSaldo() const {
    return saldo;
}

// Member Function
// Tambahkan sejumlah nominal uang ke saldo
void Rekening::simpanUang(double in) {
    saldo += in;
}

// Kurangkan sejumlah nominal uang dari saldo apabila saldo mencukupi (tidak negatif setelah dikurangkan)
// Kembalikan boolean yang mengindikasikan apakah uang berhasil ditarik atau tidak
bool Rekening::tarikUang(double in) {
    if(in > saldo) {
        return false;
    }

    saldo -= in;
    return true;
}