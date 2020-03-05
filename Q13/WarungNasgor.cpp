#include <iostream>
#include "WarungNasgor.hpp"
using namespace std;

WarungNasgor::WarungNasgor(int uang, int nasi, int telur, int kecap): WarungNasi(uang,telur,nasi) {
    this->kecap = kecap;
}

// Memasak menu Nasi Goreng
// Resep Nasi Goreng:
//     1 buah nasi
//     1 buah telur
//     1 buah kecap
// Jika bahan yang dibutuhkan kurang, kembalikan false.
// Jika cukup, hitung pendapatan total. Pendapatan total dihitung dengan jumlah pesanan dikali 15000
// Setelah itu, tambahkan pendapatan total ke uang. Kembalikan true.
bool WarungNasgor::masak(int pesanan) {
    if(getNasi() >= pesanan && getTelur() >= pesanan && kecap >= pesanan) {
        int pendapatan = pesanan * 15000;
        int current_uang = getUang() + pendapatan;
        setUang(current_uang);
        return true;
    }

    return false;
}