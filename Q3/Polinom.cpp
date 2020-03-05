#include <iostream>
#include <algorithm>
#include <cmath>
#include "Polinom.hpp"
using namespace std;

// ctor, cctor, dtor, op=
// untuk konstruktor, inisialisasi seluruh nilai koefisien dengan 0.
Polinom::Polinom() {
    derajat = 0;
    koef[0] = 0;
}    // ctor Polinom dengan orde = 0
Polinom::Polinom(int orde) {
    derajat = orde;
    for(int i = 0; i <= derajat; i++) {
        koef[i] = 0;
    }
} // ctor Polinom dengan orde = n (sesuai parameter)
Polinom::Polinom(const Polinom& in) {
    derajat = in.derajat;
    for(int i = 0; i <= derajat; i++) {
        koef[i] = in.koef[i];
    }
}
Polinom::~Polinom() {}
Polinom& Polinom::operator=(const Polinom& in) {
    derajat = in.derajat;
    for(int i = 0; i <= derajat; i++) {
        koef[i] = in.koef[i];
    }

    return *this;
}

// getter, setter
int Polinom::getKoefAt(int idx) const {
    return koef[idx];
}
int Polinom::getDerajat() const {
    return derajat;
}
void Polinom::setKoefAt(int idx, int val) {
    koef[idx] = val;
}
void Polinom::setDerajat(int orde) {
    derajat = orde;
}

// operator overloading
// Untuk setiap operator, **tidak perlu mengubah nilai derajat tertinggi**
// Orde Polinom hasil operasi adalah MAX(orde Polinom 1, orde Polinom 2)
Polinom operator+(const Polinom& pol1, const Polinom& pol2) {
    Polinom ret(max(pol1.getDerajat(),pol2.getDerajat()));

    for(int i = 0; i <= ret.getDerajat(); i++) {
        if(i > pol1.getDerajat()) {
            ret.koef[i] = pol2.koef[i];
        }
        else if(i > pol2.getDerajat()) {
            ret.koef[i] = pol1.koef[i];
        }
        else {
            ret.koef[i] = pol1.koef[i] + pol2.koef[i];
        }
    }

    return ret;
} // Penjumlahan 2 buah Polinom.
Polinom operator-(const Polinom& pol1, const Polinom& pol2) {
    Polinom ret(max(pol1.getDerajat(),pol2.getDerajat()));

    for(int i = 0; i <= ret.getDerajat(); i++) {
        if(i > pol1.getDerajat()) {
            ret.koef[i] = pol2.koef[i] * -1;
        }
        else if(i > pol2.getDerajat()) {
            ret.koef[i] = pol1.koef[i];
        }
        else {
            ret.koef[i] = pol1.koef[i] - pol2.koef[i];
        }
    }

    return ret;
} // Pengurangan 2 buah Polinom.
Polinom operator*(const Polinom& pol, const int x) {
    Polinom ret(pol);

    for(int i = 0; i <= ret.getDerajat(); i++) {
        ret.koef[i] *= x;
    }

    return ret;
} // Perkalian Polinom dengan konstanta
Polinom operator*(const int x, const Polinom& pol) {
    Polinom ret(pol);

    for(int i = 0; i <= ret.getDerajat(); i++) {
        ret.koef[i] *= x;
    }

    return ret;
} // Perkalian Polinom dengan konstanta (sifat komutatif)
Polinom operator/(const Polinom& pol, const int x) {
    Polinom ret(pol);

    for(int i = 0; i <= ret.getDerajat(); i++) {
        ret.koef[i] /= x;
    }

    return ret;
} // Pembagian bilangan bulat. Tidak perlu menangani apabila kasus pembagi = 0.

// member function
// Melakukan pembacaan koefisien sejumlah derajat Polinom, dimulai dari x^0 (konstanta)
void Polinom::input() {
    for(int i = 0; i <= derajat; i++) {
        cin >> koef[i];
    }
} 

// Mencetak seluruh koefisien polinom. Untuk setiap koefisien akhiri dengan end-of-line
// Cetaklah apa adanya dari koefisien ke-0 hingga derajat tertinggi (termasuk apabila koefisien = 0)
void Polinom::printKoef() {
    for(int i = 0; i <= derajat; i++) {
        cout << koef[i] << endl;
    }
}

// Menghitung hasil substitusi x dengan sebuah bilangan ke dalam polinom
int Polinom::substitute(int x) {
    int sum = 0;

    for(int i = 0; i <= derajat; i++) {
        sum += koef[i] * pow(x, i);
    }

    return sum;
}

// Melakukan aksi derivasi terhadap Polinom.
// Lakukan pengurangan pada derajat tertinggi Polinom. 
// Apabila derajat tertinggi = 0, hasil derivasi = 0 (dengan derajat tertinggi = 0)
Polinom Polinom::derive() {
    if(derajat == 0) {
        Polinom ret;

        return ret;
    }

    Polinom ret(derajat-1);

    for(int i = 0; i <= ret.derajat; i++) {
        ret.koef[i] = koef[i+1] * (i+1);
    }

    return ret;
}

// ** METHOD BONUS (TC 12,13,14) ** (Tidak wajib dikerjakan)
// Mencetak polinom dengan format: A+Bx^1+Cx^2+Dx^3...dst (diakhiri dengan end-of-line)
// Apabila suatu koefisien bernilai < 0, gunakan tanda "-" untuk menggantikan tanda "+"
// Apabila suatu koefisien bernilai 0, lewati koefisien tersebut dan lanjutkan ke koefisien selanjutnya
// Jika seluruh koefisien bernilai 0, keluarkan "0"
void Polinom::print() {
    bool isAllZero = true;

    if(koef[0] != 0) {
        cout << koef[0];
        isAllZero = false;
    }
    for(int i = 1; i <= derajat; i++) {
        if(koef[i] == 0) {
            continue;
        }
        else if(koef[i] > 0) {
            if(!isAllZero) {
                if(koef[i] != 1) {
                    cout << "+" << koef[i] << "x^" << i;
                }
                else {
                    cout << "+x^" << i;
                }
            }
            else {
                isAllZero = false;
                if(koef[i] != 1) {
                    cout << koef[i] << "x^" << i;
                }
                else {
                    cout << "x^" << i;
                }
            }
        }
        else {
            isAllZero = false;
            if(koef[i] != -1) {
                cout << koef[i] << "x^" << i;
            }
            else {
                cout << "-x^" << i;
            }
        }
    }

    if(isAllZero) {
        cout << "0";
    }

    cout << "\n";
}