#include <iostream>
#include "Bottle.hpp"
using namespace std;

int Bottle::numOfBottle = 0;

Bottle::Bottle(): id(++numOfBottle) {
    height = 10.00;
    radius = 10.00;
    waterHeight = 0.00;
}
/* Ctor default Bottle kosong dengan tinggi = 10.00 dan radius = 10.00 */
Bottle::Bottle(float height, float radius): id(++numOfBottle) {
    this->height = height;
    this->radius = radius;
    waterHeight = 0.00;
}
/* Ctor Bottle jika diketahui nilai tinggi dan radius, Bottle kosong*/
Bottle::Bottle(const Bottle& bottle): id(bottle.id) {
    height = bottle.height;
    radius = bottle.radius;
    waterHeight = bottle.waterHeight;
}
/* Cctor Bottle. id juga dicopy dan numOfBottle tidak bertambah */
Bottle::~Bottle() {}
/* Destruktor Bottle */

int Bottle::getId() const {
    return id;
}
/* Mengembalikan id Bottle */
float Bottle::getWaterVolume() const {
    float ret;

    ret = PI * radius * radius * waterHeight;

    return ret;
}
/* Mengembalikan volume air dalam botol */
float Bottle::getBottleVolume() const {
    float ret;

    ret = PI * radius * radius * height;

    return ret;
}
/* Mengembalikan volume botol */

void Bottle::setHeight(float height) {
    this->height = height;
    if(height < waterHeight) {
        waterHeight = height;
    }
}
/*
* Mengubah tinggi Bottle. Jika tinggi baru kurang dari tinggi air,
* maka tinggi air = tinggi yang baru.
*/

void Bottle::addWater(float waterVolume) {
    float addedWaterHeight = waterVolume / (PI * radius * radius);

    if(addedWaterHeight >= (height - waterHeight)) {
        waterHeight = height;
    }
    else {
        waterHeight += addedWaterHeight;
    }
}
/*
* Menambahkan air ke dalam botol. Jika botol tidak muat, biarkan
* botol penuh.
*/

void Bottle::substractWater(float waterVolume) {
    float substractedWaterHeight = waterVolume / (PI * radius * radius);

    if(substractedWaterHeight >= waterHeight) {
        waterHeight = 0;
    }
    else {
        waterHeight -= substractedWaterHeight;
    }
}
/*
* Mengurangi air dari botol. Jika air yang tersedia kurang, biarkan
* botol kosong.
*/

float Bottle::getWaterHeightIfVolume(float waterVolume) const {
    return waterVolume/(PI * radius * radius);
}
/*
* Mengembalikan tinggi air dari botol jika diketahui suatu volume air.
* Tinggi botol diabaikan, dianggap tidak akan terlalu penuh.
*/

void Bottle::pourWaterTo(Bottle& other) {
    float volumeToBeFilled = other.getBottleVolume() - other.getWaterVolume();
    float heightToBeSubstracted = getWaterHeightIfVolume(volumeToBeFilled); 

    if(waterHeight >= heightToBeSubstracted) {
        other.waterHeight = other.height;
        waterHeight -= heightToBeSubstracted;
    }
    else {
        other.addWater(getWaterVolume());
        waterHeight = 0;
    }
}
/*
* Menuang isi botol ini ke botol lain sampai botol ini kosong.
* Jika botol lain penuh sebelum semua air pindah, maka penuangan
* berhenti dan terdapat sisa air di botol ini.
*/