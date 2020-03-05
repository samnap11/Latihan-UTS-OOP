#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <iostream>

using namespace std;

template <class T, int a>
class Vector {
private:
    T* elements;

public:
    Vector() {
        this->elements = new T[a];
    }

    Vector(const Vector& other) {
        this->elements = new T[a];
        for(int i = 0; i < a; i++) {
            elements[i] = other.elements[i];
        }
    }

    ~Vector() {
        delete[] this->elements;
    }

    T& operator[](int idx) {
        return this->elements[idx];
    }

    Vector operator+(const Vector& other) {
        Vector result;
        for(int i = 0; i < a; i++) {
            result.elements[i] = elements[i] + other.elements[i];
        }
        return result;
    }

    Vector operator-(const Vector& other) {
        Vector result;
        for(int i = 0; i < a; i++) {
            result.elements[i] = elements[i] - other.elements[i];
        }
        return result;
    }

    bool operator<(const Vector& other) {
        for(int i = 0; i < a; i++) {
            if (elements[i] != other.elements[i]) {
                return elements[i] < other.elements[i];
            }
        }
        return false;
    }

    bool operator>(const Vector& other) {
        for(int i = 0; i < a; i++) {
            if (elements[i] != other.elements[i]) {
                return elements[i] > other.elements[i];
            }
        }
        return false;;
    }

    friend std::ostream& operator<<(ostream& os, Vector vector) {
        os << "<";
        for(int i = 0; i < a-1; i++) {
            os << vector.elements[i] << ",";
        }
        os << vector.elements[a-1];
        os << ">";
        return os;
    }

    friend std::istream& operator>>(istream& is, Vector& vector) {
        for(int i = 0; i < a; i++) {
            is >> vector.elements[i];
        }
        return is;
    }
};

#endif