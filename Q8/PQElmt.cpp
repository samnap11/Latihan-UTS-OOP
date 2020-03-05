// PQElmt.cpp
#include "PQElmt.hpp"

PQElmt::PQElmt() {
  this->value = 0;
  this->prio = 0;
}

PQElmt::PQElmt(int value, int prio) {
  this->value = value;
  this->prio = prio;
}

PQElmt::PQElmt(const PQElmt& other) {
  this->value = other.value;
  this->prio = other.prio;
}

PQElmt::~PQElmt() {
  //
}

int PQElmt::getValue() const {
  return this->value;
}

int PQElmt::getPrio() const {
  return this->prio;
}

bool PQElmt::operator==(const PQElmt& other) {
  // Implementasikan di sini
  return value == other.value && prio == other.prio;
}

bool PQElmt::operator<(const PQElmt& other) {
  // Implementasikan di sini
  if(prio == other.prio) {
      return value > other.value;
  }

  return prio < other.prio;
}

bool PQElmt::operator>(const PQElmt& other) {
  // Implementasikan di sini
  if(prio == other.prio) {
      return value < other.value;
  }

  return prio > other.prio;
}