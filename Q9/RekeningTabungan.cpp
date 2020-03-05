#include <iostream>
#include "RekeningTabungan.h"
using namespace std;

// Konstruktor menginisialisi saldo (parameter 1) dan biaya transaksi (parameter 2)
// Set biaya transaksi 0.0 apabila biaya transaksi bernilai negatif
RekeningTabungan::RekeningTabungan(double sal, double biaya): Rekening(sal) {
    biayaTransaksi = biaya;
}

// Getter, Setter
void RekeningTabungan::setBiayaTransaksi(double in) {
    biayaTransaksi = in;
}
double RekeningTabungan::getBiayaTransaksi() const {
    return biayaTransaksi;
}

// Member Function
// Panggil fungsi simpanUang dari parent class
// Kurangkan saldo dengan biaya transaksi
void RekeningTabungan::simpanUang(double in) {
    Rekening::simpanUang(in);
    double sal = getSaldo();
    sal -= biayaTransaksi;
    setSaldo(sal);
}

// Panggil fungsi tarikUang dari parent class
// Kurangkan saldo dengan biaya transaksi hanya jika penarikan uang berhasil
// Saldo mungkin saja menjadi negatif apabila setelah penarikan, saldo < biaya transaksi
// Kembalikan boolean yang mengindikasikan apakah uang berhasil ditarik atau tidak
bool RekeningTabungan::tarikUang(double in) {
    bool tmp = Rekening::tarikUang(in);
    double sal = getSaldo();

    if(tmp) {
        sal -= biayaTransaksi;
        setSaldo(sal);
    }

    return tmp;
}